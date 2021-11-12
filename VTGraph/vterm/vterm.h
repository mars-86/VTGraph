#ifndef VTERM_VTERM_H
#define VTERM_VTERM_H
#pragma once

#include "command.h"
#include "../os/os.h"

namespace vterm {

class VTerm : public Command {
public:
	VTerm()
	{
	    set_screen_buffer(VTERM_ALTERNATE_SCREEN_BUFFER);
	    _stdh = os::get_std_handle(STD_OUTPUT_HANDLE);
	    os::get_container_size(_stdh, &_cs);
	    _buffer.resize(_cs.cs_col * _cs.cs_row, {(char *)" ", 0, 0});
    }

	virtual ~VTerm()
	{
		set_cursor_visibility(VTERM_CURSOR_SHOW);
		set_screen_buffer(VTERM_MAIN_SCREEN_BUFFER);
	}

	virtual void put(char *s, int x, int y)
	{
		dwchar_t dwc = { s, x, y };
		std::cout << dwc;
	}

	virtual void put_buffer(std::vector<dwchar_t>& points)
	{
        for(auto i : points) _buffer[_cs.cs_col * (i.get_y() - 1) + i.get_x() - 1] = i.val;
	}

protected:
	typedef struct _Symbol {
		char* val;
		int x;
		int y;
	} dwchar_t;

private:
	friend std::ostream& operator<<(std::ostream& out, const dwchar_t& symbol)
	{
		// std::flush for cursor fluency
		return out << VTERM_ESCAPE << "[" << symbol.y << ";" << symbol.x << "H" << symbol.val << std::flush;
	}
    std::vector<dwchar_t> _buffer;
    HANDLE _stdh;
    os::ContainerSize _cs;

};

} // namespace vterm

#endif //!VTERM_VTERM_H

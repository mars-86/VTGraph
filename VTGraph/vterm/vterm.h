#ifndef VTERM_VTERM_H
#define VTERM_VTERM_H
#pragma once

#include <cmath>
#include "command.h"
#include "../os/os.h"
#include "../gfx/point2d.h"

#ifdef _WIN32
#define _STDOUT_HANDLE STD_OUTPUT_HANDLE
#else
#define _STDOUT_HANDLE 1
#endif // _WIN32

namespace vterm {

class VTerm : public Command {
public:
	VTerm()
	{
	    set_screen_buffer(VTERM_ALTERNATE_SCREEN_BUFFER);
	    set_cursor_visibility(VTERM_CURSOR_HIDE);
	    _stdh = os::get_std_handle(_STDOUT_HANDLE);
	    os::get_container_size(_stdh, &_cs);
	    _buffer.resize(_cs.cs_col * _cs.cs_row, 0);
	    _ratio = floor(_cs.cs_col / _cs.cs_row);
    }

	virtual ~VTerm()
	{
		set_cursor_visibility(VTERM_CURSOR_SHOW);
		set_screen_buffer(VTERM_MAIN_SCREEN_BUFFER);
	}

	virtual void put(const char *s, int x, int y)
	{
		dwchar_t dwc = { (char *)s, x, y };
		std::cout << dwc;
	}

	virtual void put(const char *s, int x, int y, int z)
	{
		dwchar_t dwc = { (char *)s, x, y };
		std::cout << dwc;
	}

	virtual void put_buffer(const std::vector<gfx::Point2D>& points)
	{
        for(auto i : points) if ((i.get_y() < (_cs.cs_row - 1)) && (i.get_x() < (_cs.cs_col - 1)))_buffer[_cs.cs_col * (i.get_y() - 1) + i.get_x() - 1] = 1;
	}

	virtual void erase_buffer(const std::vector<gfx::Point2D>& points)
	{
        for(auto i : points) if ((i.get_y() < (_cs.cs_row - 1)) && (i.get_x() < (_cs.cs_col - 1)))_buffer[_cs.cs_col * (i.get_y() - 1) + i.get_x() - 1] = 0;
	}

	virtual std::vector<int>& get_screen_buffer(void)
	{
        return _buffer;
	}

	virtual std::vector<int>& get_screen_buffer(const std::vector<gfx::Point2D>& points)
	{
	    _points_buffer.clear();
        int y = points[0].get_y();
        int width = 0;
        gfx::Point2D p1 = { points[0].get_x(), points[0].get_y() };
        for (int i = 0; i < points.size(); ++i) {
            while (y == points[i++].get_y()) ++width;
            y = points[i].get_y();

        }
        return _points_buffer;
	}

	unsigned int get_width(void)
	{
        return _cs.cs_col;
	}

	unsigned int get_height(void)
	{
        return _cs.cs_row;
	}

protected:
	typedef struct _Symbol {
		char* val;
		int x;
		int y;
	} dwchar_t;

    std::vector<int> _buffer;

private:
	friend std::ostream& operator<<(std::ostream& out, const dwchar_t& symbol)
	{
		// std::flush for cursor fluency
		return out << VTERM_ESCAPE << "[" << symbol.y << ";" << symbol.x << "H" << symbol.val << std::flush;
	}
    std::vector<int> _points_buffer;
#ifdef _WIN32
    HANDLE _stdh;
#else
    void *_stdh;
#endif // _WIN32
    os::ContainerSize _cs;
    int _ratio;

};

} // namespace vterm

#endif //!VTERM_VTERM_H

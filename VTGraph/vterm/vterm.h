#ifndef VTERM_VTERM_H
#define VTERM_VTERM_H
#pragma once

#include "command.h"

namespace vterm {

class VTerm : public Command {
public:
	VTerm() { set_screen_buffer(VTERM_ALTERNATE_SCREEN_BUFFER); }
	virtual ~VTerm()
	{ 
		set_cursor_visibility(VTERM_CURSOR_SHOW);
		set_screen_buffer(VTERM_MAIN_SCREEN_BUFFER);
	}
	
	virtual void put(char *s, int x, int y)
	{
		std::cout << (dwchar_t){s, x, y};
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

};

} // namespace vterm

#endif //!VTERM_VTERM_H

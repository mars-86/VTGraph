#ifndef VTERM_VTERM_H
#define VTERM_VTERM_H
#pragma once

#include <string>
#include "sequences.h"

namespace vterm {

class VTerm {
public:
	VTerm(){}
	virtual ~VTerm(){}

protected:
	typedef struct _Symbol {
		char* val;
		int x;
		int y;
	} dwchar_t;

public:
	friend std::ostream& operator<<(std::ostream& out, const dwchar_t& symbol)
	{
		// std::flush for cursor fluency
		return out << VTERM_ESCAPE << "[" << symbol.y << ";" << symbol.x << "H" << symbol.val << std::flush;
	}

	virtual inline void set_cursor_visibility(const char *visibility)
	{
		std::cout << VTERM_ESCAPE << visibility;
	}

	virtual inline void set_cursor_position(const char position, short n)
	{
		switch (position){
		case 'U':
			std::cout << VTERM_CURSOR_POSITION_UP(n);
			break;
		case 'D':
			std::cout << VTERM_CURSOR_POSITION_DOWN(n);
			break;
		case 'F':
			std::cout << VTERM_CURSOR_POSITION_FWARD(n);
			break;
		case 'B':
			std::cout << VTERM_CURSOR_POSITION_BWARD(n);
			break;
		default:
			;
		}
	}

	virtual inline void set_screen_buffer(const char* s_buffer)
	{
		std::cout << s_buffer;
	}

	virtual inline void set_charset(const char* charset)
	{
		std::cout << charset;
	}

	virtual inline void set_icon_title(const char* title)
	{
		std::cout << VTERM_ESCAPE << "]0;" << title << VTERM_BELL;
	}

	virtual inline void set_title(const char* title)
	{
		std::cout << VTERM_ESCAPE << "]2;" << title << VTERM_BELL;
	}

};

} // namespace vterm

#endif //!VTERM_VTERM_H

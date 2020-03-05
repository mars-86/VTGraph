#ifndef VTERM_VTERM_H
#define VTERM_VTERM_H
#pragma once

#include "sequences.h"

namespace vterm {

class VTerm {
public:
	VTerm(){}
	virtual ~VTerm(){}

protected:
	typedef struct _Symbol {
		char* val;
		int row;
		int col;
	} dwchar_t;

public:
	friend std::ostream& operator<<(std::ostream& out, const dwchar_t& symbol)
	{
		// std::flush for cursor fluency
		return out << "\x1B[" << symbol.row << ";" << symbol.col << "H" << symbol.val << std::flush;
	}

	virtual void set_cursor_visibility(const char *visibility)
	{
		std::cout << visibility;
	}
};

} // namespace vterm

#endif //!VTERM_VTERM_H

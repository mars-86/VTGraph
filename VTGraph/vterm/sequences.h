#ifndef VTERM_SEQUENCES_H
#define VTERM_SEQUENCES_H
#pragma once

#include <sstream>
#define VTERM_CURSOR_SHOW "\x1B[?25h"
#define VTERM_CURSOR_HIDE "\x1B[?25l"
inline std::string SET_CURSOR_POS(int row, int col)
{
	std::stringstream ss;
	ss << "\x1B[" << row << ";" << col << "H"; 
	std::cout << row << " " << col << std::endl;
	return ss.str();
}

#endif // !VTERM_SEQUENCES_H

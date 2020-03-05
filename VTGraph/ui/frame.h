#ifndef UI_FRAME_H
#define UI_FRAME_H
#pragma once

#include <map>
#include "container.h"
#include "graphic.h"
#include "ui_component.h"
#include "../vterm/vterm.h"

namespace ui {

using namespace vterm;

class Frame : public Container, public VTerm {
public:
	Frame(short width, short height);
	~Frame();

	const short get_max_width(void) const;
	const short get_max_height(void) const;
	void visible(void);
private:
	dwchar_t** _drawable = NULL;
	//Drawer* _drawer;
	short _curr_row = 1, _curr_col = 1;
	void _draw(const UIComponent& uic);	
	void _init(void);
	void _alloc(void);
	void _dealloc(void);
};

} // namespace ui

#endif // !UI_FRAME_H

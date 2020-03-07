#ifndef UI_FRAME_H
#define UI_FRAME_H
#pragma once

#include <map>
#include "container.h"
#include "graphic.h"
#include "ui_component.h"

namespace ui {

using namespace vterm;

class Frame : public Container {
public:
	Frame(short width, short height);
	~Frame();

	const short get_max_width(void) const;
	const short get_max_height(void) const;
	void visible(void);
private:
	//Drawer* _drawer;
	Graphic* _drawer;
	void _draw(const UIComponent& uic);	
};

} // namespace ui

#endif // !UI_FRAME_H

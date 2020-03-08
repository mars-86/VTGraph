#ifndef BAR_H
#define BAR_H
#pragma once

#include "ui_component.h"

namespace ui {

class Bar : public UIComponent {
public:
	Bar(const ComponentSize& size) : UIComponent(size, "Bar") {}
	//Bar(const ComponentSize& size, const POSITION position) : UIComponent((size, position) {}
	virtual ~Bar() {}
protected:
	//short _width;
	//short _height;
};

}

#endif // !BAR_H

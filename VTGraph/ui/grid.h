#ifndef UI_GRID_H
#define UI_GRID_H
#pragma once

#include "ui_component.h"

namespace ui {

class Grid : public UIComponent {
public:
	Grid(short rows, short cols);
	//Bar(const ComponentSize& size, const POSITION position) : UIComponent((size, position) {}
	virtual ~Grid();
protected:
	short _rows, _cols;
};

}

#endif // !UI_GRID_H

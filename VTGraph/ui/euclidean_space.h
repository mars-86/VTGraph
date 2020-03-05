#ifndef UI_EUCLIDEAN_SPACE_H
#define UI_EUCLIDEAN_SPACE_H
#pragma once

#include "ui_component.h"

namespace ui {

enum EUCLIDEAN_CONTEXT {
	_2D,
	_3D
};

class EuclideanSpace : public UIComponent {
public:
	EuclideanSpace(short width, short height, POSITION position);
	EuclideanSpace(EUCLIDEAN_CONTEXT context, short width, short height, POSITION position);
	~EuclideanSpace();

private:
	EUCLIDEAN_CONTEXT _e_context = EUCLIDEAN_CONTEXT::_2D;
};

}

#endif // !UI_EUCLIDEAN_SPACE_H

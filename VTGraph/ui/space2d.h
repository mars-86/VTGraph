#ifndef UI_EUCLIDEAN_SPACE_H
#define UI_EUCLIDEAN_SPACE_H
#pragma once

#include "ui_component.h"
#include "geometric.h"
#include "layer.h"
#include "../gfx/point2d.h"

namespace ui {

enum class SPACE_CONTEXT {
	_2D,
	_3D
};

enum class SPACE_AXIS {
	SIGNED,
	SIGNED_X,
	SIGNED_Y,
	UNSIGNED_X,
	UNSIGNED_Y
};

class EuclideanSpace : public UIComponent, public Geometric {
public:
	EuclideanSpace(short width, short height, ui::POSITION position);
	EuclideanSpace(EUCLIDEAN_CONTEXT context, short width, short height, ui::POSITION position);
	~EuclideanSpace();

	bool is_euclidean_space(void) const;
	const std::string& get_context(void) const;

	void on_click(void) {};
private:
	std::string _e_context = "2D";
	EUCLIDEAN_AXIS _e_axis = EUCLIDEAN_AXIS::SIGNED;
	ui::Layer _ly(0, 0, 0);
	std::vector<_ly> _layers;

	void _draw_axis(void);
    void _draw_axis_xy(void);
    void _draw_axis_xyz(void);
};

}

#endif // !UI_EUCLIDEAN_SPACE_H

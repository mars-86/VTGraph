#ifndef UI_EUCLIDEAN_SPACE_H
#define UI_EUCLIDEAN_SPACE_H
#pragma once

#include "ui_component.h"
#include "geometric.h"
#include "layer.h"
#include "../gfx/point2d.h"
// #include "graphic.h"

namespace ui {

enum class EUCLIDEAN_CONTEXT {
	_2D,
	_3D
};

enum class EUCLIDEAN_AXIS {
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
    typedef LayerT<gfx::Point2D> Layer2D;
    typedef std::vector<Layer2D> Layer;
	std::string _e_context = "2D";
	EUCLIDEAN_AXIS _e_axis = EUCLIDEAN_AXIS::SIGNED;
	Layer _layers;
};

}

#endif // !UI_EUCLIDEAN_SPACE_H

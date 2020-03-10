#ifndef UI_GEOMETRIC_H
#define UI_GEOMETRIC_H
#pragma once

#include <string>
#include "../gfx/gfx.h"

namespace ui {

using namespace gfx;

class Geometric {
public:
	Geometric();
	~Geometric();
	void draw_rect(const Rect& rect, const Color& color);
	void fill_rect(const Rect& rect, const Color& color);
	void draw_circle(const Circle& rect, const Color& color);
	void fill_circle(const Circle& rect, const Color& color);
	void draw_ellipse(const Ellipse& rect, const Color& color);
	void fill_ellipse(const Ellipse& rect, const Color& color);
private:
	void _draw_function(const std::vector<Point2D> points);
};

}

#endif // !UI_GEOMETRIC_H

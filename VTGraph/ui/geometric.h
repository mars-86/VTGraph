#ifndef UI_GEOMETRIC_H
#define UI_GEOMETRIC_H
#pragma once

#include <vector>
#include "../gfx/gfx.h"

namespace ui {

using namespace gfx;

class Geometric {
public:
	Geometric();
	~Geometric();
	void draw_line(int x1, int y1, int x2, int y2, const Color& color);
	void draw_rect(int x, int y, int width, int height, const Color& color);
	void fill_rect(const Rect& rect, const Color& color);
	void draw_circle(const Circle& rect, const Color& color);
	void fill_circle(const Circle& rect, const Color& color);
 	// void draw_ellipse(const Ellipse& rect, const Color& color);
	// void fill_ellipse(const Ellipse& rect, const Color& color);
	const std::vector<Point2D>& get_points(void) const;
protected:
	void _draw_function(const std::vector<Point2D> points);
	std::vector<Point2D> _points;
};

}

#endif // !UI_GEOMETRIC_H

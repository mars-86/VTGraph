#include "geometric.h"

namespace ui {

Geometric::Geometric() {}

Geometric::~Geometric() {}

void Geometric::draw_line(int x1, int y1, int x2, int y2, const Color& color)
{
	Line line(x1, -1 * y1, x2, -1 * y2);
	_points.insert(_points.end(), line.get_bounds().begin(), line.get_bounds().end());
}

void Geometric::draw_rect(int x, int y, int width, int height, const Color& color)
{
	Rect rect(x, -1 * y, width, -1 * height);
	_points.insert(_points.end(), rect.get_bounds().begin(), rect.get_bounds().end());
}

void Geometric::fill_rect(const Rect& rect, const Color& color) {}

void Geometric::draw_circle(const Circle& rect, const Color& color) {}

void Geometric::fill_circle(const Circle& rect, const Color& color) {}

void Geometric::draw_ellipse(const Ellipse& rect, const Color& color) {}

void Geometric::fill_ellipse(const Ellipse& rect, const Color& color) {}

void Geometric::_draw_function(const std::vector<Point2D> points) {}

const std::vector<Point2D>& Geometric::get_points(void) const
{
	return _points;
}

} // namespace ui

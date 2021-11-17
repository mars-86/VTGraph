#ifndef GFX_RECT_H
#define GFX_RECT_H
#pragma once

#include <vector>
#include "shape2d.h"
#include "line.h"

namespace gfx {

template <typename T>
class RectT : public Shape2DT<T> {
public:
	RectT()
		: _x(0), _y(0), _w(0), _h(0) {}

	RectT(T x, T y, T width, T height)
		: _x(x), _y(y), _w(width), _h(height)
	{
		draw(x, y, width, height);
	}

	RectT(T x, T y, T width, T height, const Color& color)
		: _x(x), _y(y), _w(width), _h(height)
	{
		this->set_color(color.get_rgba());
		draw(x, y, width, height);
	}

	virtual ~RectT()
	{
		this->_points.clear();
	}

	void draw(T x, T y, T width, T height)
	{
		std::vector<Point2DT<T>> e1 = Line(x, y, x + width, y).get_bounds();
		std::vector<Point2DT<T>> e2 = Line(x + width, y, x + width, y + height).get_bounds();
		std::vector<Point2DT<T>> e3 = Line(x + width, y + height, x, y + height).get_bounds();
		std::vector<Point2DT<T>> e4 = Line(x, y + height, x, y).get_bounds();
		this->_points.insert(this->_points.end(), e1.begin(), e1.end());
		this->_points.insert(this->_points.end(), e2.begin(), e2.end());
		this->_points.insert(this->_points.end(), e3.begin(), e3.end());
		this->_points.insert(this->_points.end(), e4.begin(), e4.end());
	}

	void set_size(T width, T height) {};

	T get_width(void) const
	{
		return _w;
	}

	T get_height(void) const
	{
		return _h;
	}

	double get_size(void) const
	{
		return 0;
	}

	double get_area(void) const
	{
		return 0;
	}

	void translate(const Point2DT<T>& point)
	{
        this->_points.clear();
        this->draw(point.get_x(), point.get_y(), this->get_width(), this->get_height());
	}

protected:
	T _x, _y, _w, _h;
};

typedef RectT<int> Rect;
typedef RectT<double> RectF;

} // namespace gfx

#endif // !GFX_RECT_H

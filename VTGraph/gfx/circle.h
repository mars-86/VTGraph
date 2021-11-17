#ifndef GFX_CIRCLE_H
#define GFX_CIRCLE_H
#pragma once

#include <cmath>
#include "shape2d.h"

namespace gfx {

template <typename T>
class CircleT : public Shape2DT<T> {
public:
	CircleT()
		: _x(0), _y(0), _radius(0) {}

	CircleT(T x, T y, T radius)
		: _x(x), _y(y), _radius(radius)
	{
		draw(x, y, radius);
	}

	CircleT(T x, T y, T radius, const Color& color)
		: _x(x), _y(y), _radius(radius)
	{
		this->set_color(color.get_rgba());
		draw(x, y, radius);
	}

	~CircleT()
	{
		this->_points.clear();
	};

	void draw(T x, T y, T radius, T _ = 0)
	{
		T x0 = 0,
			y0 = radius,
			p0 = 1 - radius; // 5 / 4 - r
			this->_points.insert(this->_points.end(), {
				{x + x0, y + y0}, {x - x0, y - y0/* - 1*/}
			});
		while (x0 < y0) {
			x0 += 1;
			if (p0 < 0)
				p0 += (x0 << 1) + 1;
			else{
				y0 -= 1;
				p0 += (x0 << 1) + 1 - (y0 << 1);
			}
			// insert points for all octants
			this->_points.insert(this->_points.end(), {
				{x + x0, y + y0}, {x + y0, y + x0},
				{x - x0, y - y0/* - 1*/}, {x - y0, y - x0/* - 1*/},
				{x + x0, y - y0/* - 1*/}, {x + y0, y - x0/* - 1*/},
				{x - x0, y + y0}, {x - y0, y + x0}
			});
		}
	}

	void set_size(T width, T height) {}

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
        // this->draw();
	}

private:
	T _x, _y, _radius;
};

typedef CircleT<int> Circle;
typedef CircleT<double> CircleF;

} // namespace gfx

#endif // !GFX_CIRCLE_H

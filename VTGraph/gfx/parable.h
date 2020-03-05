#ifndef GFX_PARABLE_H
#define GFX_PARABLE_H
#pragma once

#include <cmath>
#include <iostream>
#include "shape2d.h"
#include "point2d.h"

namespace gfx {

template <typename T>
class ParableT : public Shape2DT<T> {
public:
	ParableT()
		: _x(0), _y(0), _rx(0), _ry(0) {}

	ParableT(T x, T y, T rx, T ry)
		: _x(x), _y(y), _rx(rx), _ry(ry)
	{
		draw(x, y, rx, ry);
	}

	ParableT(T x, T y, T rx, T ry, const Color& color)
		:  _x(x), _y(y), _rx(rx), _ry(ry)
	{
		this->set_color(color.get_rgba());
		draw(x, y, rx, ry);
	}

	~ParableT()
	{
		this->_points.clear();	
	}

	void draw(T x, T y, T rx, T ry)
	{
		// Middle point algorithm based
		T x0 = 0, y0 = 0, p0 = 1;
		while (x0 <= 30) {
			++x0;
			if (p0 < 0)
				++p0;
			else{
				++y0;
				p0 -= (y0 << 1) + 1;
			}
			this->_points.insert(this->_points.end(), {
				{(x + x0), (y + y0) }, {(x - x0), (y + y0)}
			});
		}
	}

	void set_size(T width, T height){}

	double get_size(void) const
	{
		return 0;
	}

	double get_area(void) const
	{
		return 0;
	}
private:
	T _x, _y, _rx, _ry;
};

typedef ParableT<int> Parable;
typedef ParableT<double> ParableF;

} // namespace gfx

#endif // !GFX_PARABLE_H

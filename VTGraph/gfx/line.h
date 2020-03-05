#ifndef GFX_LINE_H
#define GFX_LINE_H
#pragma once

#include <cmath>
#include "shape2d.h"

namespace gfx {

template <typename T>
class LineT : public Shape2DT<T> {
public:
	LineT()
		: _x1(0), _y1(0), _x2(0), _y2(0) {}
	
	LineT(T x1, T y1, T x2, T y2)
		: _x1(0), _y1(0), _x2(0), _y2(0)
	{
		draw(x1, y1, x2, y2);
	}

	LineT(T x1, T y1, T x2, T y2, const Color& color)
		: _x1(0), _y1(0), _x2(0), _y2(0)
	{
		this->set_color(color.get_rgba());
		draw(x1, y1, x2, y2);
	}

	~LineT()
	{
		this->_points.clear();	
	}

	void draw(T x1, T y1, T x2, T y2)
	{
		T dx = std::abs(x2-x1),
			sx = x1 < x2 ? 1 : -1,
			dy = -std::abs(y2 - y1),
			sy = y1 < y2 ? 1 : -1,
			e1 = dx + dy;  /* error value e_xy */
		while (true){   /* loop */
			this->_points.push_back({ x1, y1 });
			if( x1 == x2 && y1 == y2) break;
			int e2 = e1 << 1; 
			if (e2 >= dy){ 
				e1 += dy; /* e_xy+e_x > 0 */
				x1 += sx;
			}
			if (e2 <= dx){ /* e_xy+e_y < 0 */
				e1 += dx;
				y1 += sy;
			}
		}
	}
	
	void set_size(T width, T height) {};
	
	double get_size(void) const
	{
		return 0;
	}
	
	double get_area(void) const
	{
		return 0;
	}
private:
	T _x1, _y1, _x2, _y2;
};

typedef LineT<int> Line;
typedef LineT<double> LineF;

} // namespace gfx

#endif // !GFX_LINE_H

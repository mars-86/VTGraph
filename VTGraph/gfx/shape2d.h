#ifndef GFX_SHAPE_2D_H
#define GFX_SHAPE_2D_H
#pragma once

#include <vector>
#include "shape.h"
#include "point2d.h"

namespace gfx {

template <typename T>
class Shape2DT : public Shape {
public:
	Shape2DT() {}
	virtual ~Shape2DT() {}
	virtual double get_area(void) const = 0;
	//std::vector<Point2DT<T>>& get_points(void) { return _points; }
	const std::vector<Point2DT<T>>& get_bounds(void) const { return _points; }
	const Point2DT<T>& get_origin(void) const { return _points[0]; }
protected:
	std::vector<Point2DT<T>> _points;
	friend std::ostream& operator<<(std::ostream& out, const Point2DT<T>& point)
	{
		return out << "{" << point.get_x() << ", " << point.get_y() << "}" << std::endl;
	}
};

typedef Shape2DT<int> Shape2D;
typedef Shape2DT<double> Shape2DF;

} // namespace gfx

#endif // !GFX_SHAPE_2D_H

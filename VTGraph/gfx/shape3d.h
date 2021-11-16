#ifndef GFX_SHAPE_3D_H
#define GFX_SHAPE_3D_H
#pragma once

#include <vector>
#include "shape.h"
#include "point3d.h"

namespace gfx {

template <typename T>
class Shape3DT : public Shape {
public:
	Shape3DT() {}
	virtual ~Shape3DT() {}
	virtual double get_area(void) const = 0;
	virtual void translate(const Point3DT<T>& point) = 0;
	std::vector<Point3DT<T>>& get_points(void) { return _points; }
	const std::vector<Point3DT<T>>& get_points(void) const { return _points; }
protected:
	std::vector<Point3DT<T>> _points;
	friend std::ostream& operator<<(std::ostream& out, const Point3DT<T>& point)
	{
		return out << "{" << point.get_x() << ", " << point.get_y() << ", " << point.get_z() << "}" << std::endl;
	}
};

typedef Shape3DT<int> Shape3D;
typedef Shape3DT<double> Shape3DF;

} // namespace gfx

#endif // !GFX_SHAPE_3D_H

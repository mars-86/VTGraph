#ifndef GFX_POINT_3D_H
#define GFX_POINT_3D_H

#include "point2d.h"

namespace gfx {

template <typename T>
class Point3DT : public Point2DT<T> {
public:
	Point3DT() : Point2DT<T>(0, 0), _z(0) {}
	Point3DT(T x, T y, T z) : Point2DT<T>(x, y), _z(z) {}
	~Point3DT() {}
		
	void set_z( T z ) { _z = z; }
	T get_z(void) const { return _z; }
private:
	T _z;
};

typedef Point3DT<int> Point3D;
typedef Point3DT<double> Point3DF;

} // namespace gfx

#endif // !GFX_POINT_3D_H

#ifndef GFX_GFX_H
#define GFX_GFX_H
#pragma once

#include "shape2d.h"
#include "shape3d.h"
#include "point2d.h"
#include "point3d.h"
#include "line.h"
#include "rect.h"
#include "square.h"
#include "circle.h"
#include "ellipse.h"
#include "parable.h"

namespace gfx {

template <typename T>
class GFXT {
public:
	GFXT(int ratio) : _ratio(ratio) {}
	~GFXT() {}

	gfx::Circle circle(T x, T y, T radius, const gfx::Color& color)
	{
	    return gfx::CircleT<T>(x, y, radius, color);
	}

	gfx::Ellipse ellipse(T x, T y, T rx, T ry, const Color& color)
	{
	    T yt = y - (y % _ratio), rt = ry / _ratio;
	    return gfx::EllipseT<T>(x, yt, rx, rt, color);
	}

	gfx::Line line(T x1, T y1, T x2, T y2, const Color& color)
	{
        T y1t = floor(y1 / _ratio), div = y2 / _ratio, y2t = (div > y1) ? div : y2;
        return gfx::LineT<T>(x1, y1t, x2, y2t, color);
	}

	gfx::Parable parable(T x, T y, T rx, T ry, const Color& color)
	{
        return gfx::ParableT<T>(x, y, rx, ry, color);
	}

	gfx::Rect rectangle(T x, T y, T width, T height, const Color& color)
	{
	    T yt = y - (y % _ratio), ht = height / _ratio;
        return gfx::RectT<T>(x, yt, width, ht, color);
	}

	gfx::Square& square(T x, T y, T size, const Color& color)
	{
        T yt = y - (y % _ratio), st = size / _ratio;
        // return dynamic_cast<gfx::Square&>(gfx::RectT<T>(x, yt, size, st, color));
	}

private:
    int _ratio;
};

typedef GFXT<int> GFX;
typedef GFXT<double> GFXF;

} // namespace gfx

#endif // !GFX_GFX_H

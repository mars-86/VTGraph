#ifndef GFX_SQUARE_H
#define GFX_SQUARE_H
#pragma once

#include <vector>
#include "rect.h"

namespace gfx {

template <typename T>
class SquareT : public RectT<T> {
public:
	SquareT()
		: RectT<T>() {}

	SquareT(T x, T y, T size)
		: RectT<T>(x, y, size, size)
	{
		this->draw(x, y, size, size);
	}

	SquareT(T x, T y, T size, const Color& color)
		: RectT<T>(x, y, size, size)
	{
		this->set_color(color.get_rgba());
		this->draw(x, y, size, size);
	}

	~SquareT() {}
};

typedef SquareT<int> Square;
typedef SquareT<double> SquareF;

} // namespace gfx

#endif // GFX_SQUARE_H

#ifndef GFX_SHAPE_H
#define GFX_SHAPE_H
#pragma once

#include <iostream>
#include "color.h"

namespace gfx {

class Shape {
public:
	Shape() : _color({0, 0, 0, 0}) {}
	virtual ~Shape(){}
	virtual void draw(int x1, int y1, int x2, int y2) = 0;
	virtual void set_size(int width, int height) = 0;
	virtual double get_size(void) const = 0;
	virtual void set_color(const RGBA& color) { _color.set_rgba(color); }
	virtual const Color& get_color(void) const { return _color; }
protected:
	Color _color;
};

} // namespace gfx

#endif // !GFX_SHAPE_H
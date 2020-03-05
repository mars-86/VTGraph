#ifndef UI_GRAPHIC_H
#define UI_GRAPHIC_H
#pragma once

#include <vector>
#include "region.h"
#include "../gfx/line.h"
#include "../gfx/rect.h"

namespace ui {

using namespace gfx;

template <typename T>
class Graphic {
public:
	Graphic(T drawable)
		: _drawable( drawable ) {}
	//Graphic(T** drawable, Context& context)
	//	: _drawable(drawable), _context(context) {};
	~Graphic() {}

	void draw_rect(const Rect& rect, Color color)
	{

		//std::cout << _drawable << std::endl;
		//_draw(fm, rect.get_bounds());
		/*for (auto& i : rect.get_bounds())
			drawable[i.get_x()][i.get_y()].val = (char*)"\u2550";

		for (int i = 0; i < rect.get_height(); ++i)
			for (int j = 0; j < rect.get_width(); ++j)
				std::cout << drawable[i][j].val;*/
	}
	void fill_rect(const Rect& rect, Color color) {}
private:
	Region region;
	T** _drawable;
	// drawing context
	//Context _context;
	//void _draw(Frame& fm, const std::vector<Point2D> points);
};

} // namespace ui

#endif // !UI_GRAPHIC_H

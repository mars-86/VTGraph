#ifndef UI_GRAPHIC_H
#define UI_GRAPHIC_H
#pragma once

#include <vector>
#include "../gfx/point2d.h"
#include "../gfx/point3d.h"
#include "../gfx/line.h"
#include "../gfx/rect.h"
#include "../vterm/vterm.h"
#include "region.h"
#include "container.h"
#include "ui_component.h"
#include "euclidean_space.h"
#include "menubar.h"
#include "table.h"
#include "../gfx/shape2d.h"

namespace ui {

using namespace gfx;
using namespace vterm;

constexpr unsigned int pixel_map[4][2] = {
    {0x01, 0x08},
    {0x02, 0x10},
    {0x04, 0x20},
    {0x40, 0x80}
};

class Graphic : public VTerm {
public:
	Graphic(short w_ratio, short h_ratio);
	Graphic(void *context, short w_ratio, short h_ratio);
	~Graphic();

	void draw(const char *s, int x, int y);
	void draw(const char *s, int x, int y, int z);
	void draw(const std::vector<Point2D>& points);
	void draw(const std::vector<Point3D>& points);
	void draw(const Shape2D& shape);
	void erase(int x, int y);
	void erase(int x, int y, int z);
	void erase(const std::vector<Point2D>& points);
	void erase(const std::vector<Point3D>& points);
	void erase(const Shape2D& shape);
	const char* _gen_symbol(const std::vector<Point2D>& points);
	void print(void);
	void draw_rect(const Rect& rect, const Color& color);
	void fill_rect(const Rect& rect, const Color& color);
	void draw_component(const Container& uic);
	void draw_component(const UIComponent& uic);
	// void draw_component(const EuclideanSpace& espc);
	void draw_component(const MenuBar& tbar);
	void draw_component(const Table& tab);
	const void set_region(const UIComponent& uic, const gfx::Rect& rect);
	const Region& get_region(const gfx::Rect& rect);

private:
    short _w_ratio, _h_ratio;
	short _dwable_w, _dwable_h;
	int _linear_length;
	std::string _dwable;
};

} // namespace ui

#endif // !UI_GRAPHIC_H

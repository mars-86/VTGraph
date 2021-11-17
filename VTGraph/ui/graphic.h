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

class Graphic : public VTerm {
public:
	Graphic(short dwable_w, short dwable_h);
	Graphic(void *context, short dwable_w, short dwable_h);
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
	void draw_component(const EuclideanSpace& espc);
	void draw_component(const MenuBar& tbar);
	void draw_component(const Table& tab);
	const void set_region(const UIComponent& uic, const gfx::Rect& rect);
	const Region& get_region(const gfx::Rect& rect);
private:
	friend class Frame;
	dwchar_t** _drawable = nullptr;
	short _dwable_w, _dwable_h;
	short _curr_row = 1, _curr_col = 1;
	void _set_row_col(const Rect& drawed);
	void _draw_at(char* str, short x, short y);
	void _draw_at(char* str, int x, int y);
	void _top_left_edge(const Point2D& ori, const Rect& rect);
	void _top_right_edge(const Point2D& ori, const Rect& rect);
	void _bottom_left_edge(const Point2D& ori, const Rect& rect);
	void _bottom_right_edge(const Point2D& ori, const Rect& rect);
	void _init(void);
	void _alloc(void);
	void _dealloc(void);
};

} // namespace ui

#endif // !UI_GRAPHIC_H

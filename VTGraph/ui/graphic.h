#ifndef UI_GRAPHIC_H
#define UI_GRAPHIC_H
#pragma once

#include "../gfx/line.h"
#include "../gfx/rect.h"
#include "../vterm/vterm.h"
#include "region.h"
#include "ui_component.h"

namespace ui {

using namespace gfx;
using namespace vterm;

class Graphic : public VTerm {
public:
	Graphic(short dwable_w, short dwable_h);
	~Graphic();

	void draw_rect(const Rect& rect, Color color);
	void fill_rect(const Rect& rect, Color color);
	void draw_component(const UIComponent& uic);
	const void set_region(const UIComponent& uic, const gfx::Rect& rect);
	const Region& get_region(const gfx::Rect& rect);
private:
	dwchar_t** _drawable = NULL;
	short _dwable_w, _dwable_h;
	short _curr_row = 1, _curr_col = 1;
	void _init(void);
	void _alloc(void);
	void _dealloc(void);
};

} // namespace ui

#endif // !UI_GRAPHIC_H

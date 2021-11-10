#ifndef CANVAS_H
#define CANVAS_H
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../vterm/vterm.h"
#include "../gfx/gfx.h"
#include "layer.h"

#ifdef _DEVELOPMENT
#include "../base/debug_tools.h"
#endif

namespace ui {

enum AXIS_TYPE {
	SIGNED,
	UNSIGNED,
	UNSIGNED_X,
	UNSIGNED_Y
};

using namespace vterm;
using namespace gfx;

class Canvas : public VTerm {
public:
	Canvas();
	Canvas(short rows, short cols);
	Canvas(short rows, short cols, AXIS_TYPE type);
	~Canvas();

	Point2D get_center(void) const;
	void draw(gfx::Shape2D& sh, short layer);
	void draw(const std::vector<Point2D>& points, Color color);
	void draw(const std::vector<Point2D>& points, short layer);
	void draw(gfx::Shape2D& s1, gfx::Shape2D& s2, gfx::Shape2D& s3);
	void translate(const gfx::Shape2D& shape, int x, int y);
	void translate(const std::vector<Point2D>& points, int x, int y);
	//void translate(gfx::Shape2D& shape, int x, int y);
	//void translate(std::vector<Point2D>& points, int x, int y);
	void rotate(const gfx::Shape2D& shape, short angle);
	void rotate(const std::vector<Point2D>& points, short angle);
	void rotate(gfx::Shape2D& shape, short angle);
	void rotate(std::vector<Point2D>& points, short angle);
	void put_char(const char* s, int x, int y);
	void set_size(short rows, short cols);
	void show_axis(const std::string& axis);
	void print(void);
	void flush(void);

private:
	short _width;
	short _height;
	short _ratio;
	Point2D _center;
	//char16_t **_canvas = nullptr;
	dwchar_t** _canvas = nullptr;
	std::vector<Point2D> _write_buff;
	// std::vector<Layer2D> _layers;
	int _write_buff_offset = 0;
	AXIS_TYPE _axis_type;// = SIGNED;

	void _init(void);
	void _alloc(void);
	void _dealloc(void);
	void _show_x_axis(Point2D& center);
	void _show_y_axis(Point2D& center);
	void _set_center(const Point2D& center);
	short _get_ratio(void) const;
	const char* _gen_symbol(const std::vector<Point2D>& points, int curr_pos);
};

} // namespace ui

#endif // CANVAS_H

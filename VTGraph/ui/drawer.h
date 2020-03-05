#ifndef DRAWER_H
#define DRAWER_H
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../vterm/vterm.h"
#include "../gfx/gfx.h"

#ifdef _DEVELOPMENT
#include "../base/debug_tools.h"
#endif

namespace ui {

	using namespace vterm;
	using namespace gfx;

	class Drawer : public VTerm {
	public:
		Drawer();
		~Drawer();
		//template <typename T> void draw(T obj);
		template <typename T> void draw(T obj);
		/*Drawer(short rows, short cols);
		Drawer(short rows, short cols, AXIS_TYPE type);
		~Drawer();

		void draw(gfx::Shape2D& sh);
		void draw(const std::vector<Point2D>& points, Color color);
		void draw(const std::vector<Point2D>& points);
		void draw(gfx::Shape2D& s1, gfx::Shape2D& s2, gfx::Shape2D& s3);
		void put_char(const char* s, int x, int y);
		void print(void);
		void flush(void);

	private:
		short _rows;
		short _cols;
		short _ratio;
		Point2D _center;
		//char16_t **_canvas = nullptr;
		dwchar_t** _canvas = nullptr;
		dwchar_t** _drawable = nullptr;
		std::vector<Point2D> _write_buff;
		int _write_buff_offset = 0;
		AXIS_TYPE _axis_type;// = SIGNED;

		void _init(void);
		const char* _gen_symbol(const std::vector<Point2D>& points, int curr_pos);*/
	};

} // namespace ui

#endif // DRAWER_H

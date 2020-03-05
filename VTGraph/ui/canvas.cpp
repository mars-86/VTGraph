#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <cstdarg>
#include <stdlib.h>
#include "../ui/canvas.h"
#include "../base/base.h"

#undef _DEVELOPMENT

namespace ui {

	Canvas::Canvas() {}

	Canvas::Canvas(short rows, short cols)
		:_rows(rows), _cols(cols), _ratio(floor(_cols / _rows))
	{
		_init();
	}

	Canvas::Canvas(short rows, short cols, AXIS_TYPE type)
		: _rows(rows), _cols(cols), _ratio(floor(_cols / _rows)), _axis_type(type)
	{
		_init();
	}

	Canvas::~Canvas()
	{
		_dealloc();
	}

	std::ostream& operator<<(std::ostream& out, const Point2D& point)
	{
		return out;
	}

	Point2D Canvas::get_center(void) const
	{
		return _center;
	}

	void Canvas::draw(gfx::Shape2D& shape)
	{
		draw(shape.get_bounds());//, shape.get_color());
	}

	void Canvas::draw(const std::vector<Point2D>& points)
	{
		for (int i = 0; i < (int)points.size(); ++i)
			put_char(_gen_symbol(points, i), points[i].get_x(), points[i].get_y());
		print();
		// move cursor to the end
		dwchar_t end = { (char*)"", _rows - 1, _cols - 1 };
		std::cout << end;
	}

	void Canvas::draw(const std::vector<Point2D>& points, Color color)
	{
		char sym[22];
		for (int i = 0; i < (int)points.size(); ++i) {
			base::strcat_all(sym, 22, "sdcdcdcs", "\x1B[38;2;", color.get_red(), ';', color.get_green(), ';', color.get_blue(), 'm', _gen_symbol(points, i));
			put_char(sym, points[i].get_x(), points[i].get_y());
		}
		print();
		// move cursor to the end
		dwchar_t end = { (char*)"", _rows - 1, _cols - 1 };
		std::cout << end;
	}

	void Canvas::draw(gfx::Shape2D& s1, gfx::Shape2D& s2, gfx::Shape2D& s3)
	{
		/*void (Canvas::* dw)(gfx::Shape2D&) = &Canvas::draw;
		std::thread t1(dw, s1);
		std::thread t2(dw, s2);
		std::thread t3(dw, s3);

		t1.join();
		t2.join();
		t3.join();*/
	}

	/*void Canvas::translate(const gfx::Shape2D& shape, int x, int y)
	{
		translate(shape.get_points(), x, y);
	}

	void Canvas::translate(const std::vector<Point2D>& points, int x, int y)
	{
		std::vector<Point2D> points_p;
		for (const auto& i : points)
			points_p.push_back({ (int)(i.x + x), (int)(i.y + y) } );
		flush();
		draw(points_p);
	}*/

	void Canvas::translate(const gfx::Shape2D& shape, int x, int y)
	{
		translate(shape.get_bounds(), x, y);
	}

	void Canvas::translate(const std::vector<Point2D>& points, int x, int y)
	{
		std::vector<Point2D>& points_p = const_cast<std::vector<Point2D>&>(points);
		for (auto& i : points_p) {
#ifdef _DEVELOPMENT
			_DEBUG_PRINTF(NORMAL, "%s%d%s%d%s%d%s%d%s", "{ ", i.y, ", ", i.x, " } -> { ", (int)(i.x + x), ", ", (int)(i.y + y), " } | " );
#endif
			i.set_x(i.get_x() + x);
			i.set_y(i.get_y() + y);
		}
		flush();
		draw(points_p);
	}

	void Canvas::rotate(const gfx::Shape2D& shape, short angle)
	{
		rotate(shape.get_bounds(), angle);//, shape.get_color());
	}
	
	void Canvas::rotate(const std::vector<Point2D>& points, short angle)
	{
		std::vector<Point2D> points_p;
		double theta = angle * 3.14 / 180;
		double sth = sin(theta), cth = cos(theta);
		Point2D c = get_center();
		Point2D orig = { points[0].get_x(), points[0].get_y() };
		_set_center({ (c.get_x() - orig.get_y() / _ratio), c.get_y() + orig.get_x() });
		for (const auto& i : points) {
#ifdef _DEVELOPMENT
			_DEBUG_PRINTF(NORMAL, "%s%d%s%d%s%d%s%d%s", "{ ", i.y, ", ", i.x, " } -> { ", (int)(i.x * cth - i.y * sth), ", ", (int)(i.x * sth + i.y * cth), " } | " );
#endif
			points_p.push_back({ (int)((i.get_x() - orig.get_x()) * cth - (i.get_y() - orig.get_y()) * sth), (int)((i.get_x() - orig.get_x()) * sth + (i.get_y() - orig.get_y() ) * cth)} );

		}
		flush();
		draw(points_p);
		_set_center(c);
	}

	void Canvas::rotate(gfx::Shape2D& shape, short angle)
	{
		rotate(shape.get_bounds(), angle);//, shape.get_color());
	}
	
	void Canvas::rotate(std::vector<Point2D>& points, short angle)
	{
		std::vector<Point2D> points_p;
		double theta = angle * 3.14 / 180;
		double sth = sin(theta), cth = cos(theta);
		Point2D c = get_center();
		Point2D orig = { points[0].get_x(), points[0].get_y() };
		//translate(points, points[0].x, points[0].y);
		//Point ct = get_center();
		//_set_center({ (ct.x - (short)floor(points[0].y / _ratio)), ct.y + points[0].x });
		_set_center({ (c.get_x() - orig.get_y() / _ratio), c.get_y() + orig.get_x() });
		//_set_center({ (c.y + 2 / _ratio), c.x + 2 });
		for (auto& i : points) {
#ifdef _DEVELOPMENT
			_DEBUG_PRINTF(NORMAL, "%s%d%s%d%s%d%s%d%s", "{ ", i.y, ", ", i.x, " } -> { ", (int)(i.x * cth - i.y * sth), ", ", (int)(i.x * sth + i.y * cth), " } | " );
#endif
			points_p.push_back({ (int)((i.get_x() - orig.get_x()) * cth - (i.get_y() - orig.get_y()) * sth), (int)((i.get_x() - orig.get_x()) * sth + (i.get_y() - orig.get_y() ) * cth)} );

		}
		//points.clear();
		//points.insert(points.begin(), points_p.begin(), points_p.end());
		flush();
		draw(points_p);
		//translate(points, -points[0].x, -points[0].y);
		_set_center(c);
	}

	void Canvas::put_char(const char* s, int x, int y)
	{
		Point2D center = get_center();
		// adjust y-axis to x-axis
		Point2D coords = { (center.get_x() - (short)floor(y / _ratio)), center.get_y() + x };
		_write_buff.push_back(coords);
		_canvas[coords.get_x()][coords.get_y()] = { (char*)s, coords.get_x(), coords.get_y() };
	}

	void Canvas::set_size(short rows, short cols)
	{
		_rows = rows;
		_cols = cols;
	}

	void Canvas::show_axis(const std::string& axis)
	{
		Point2D c = get_center();
		if (axis.find("x") != std::string::npos)
			_show_x_axis(c);
		if (axis.find("y") != std::string::npos)
			_show_y_axis(c);
	}

	void Canvas::print(void)
	{
		for (auto i = _write_buff.begin() + _write_buff_offset; i != _write_buff.end(); ++i) {
#ifdef _DEVELOPMENT
			_DEBUG_PRINTF(NORMAL, "%s%d%s%d%s", "{ ", i->y, ", ", i->x, " }");
#endif
			std::cout << _canvas[i->get_x()][i->get_y()];
			std::this_thread::sleep_for(std::chrono::milliseconds(0));
		}
		// reset color - apply text bright
		std::cout << "\x1B[0m" << "\x1B[1m";
		_write_buff_offset += _write_buff.size() - _write_buff_offset;
	}

	void Canvas::flush(void)
	{
		for (const auto& i : _write_buff) {
			_canvas[i.get_x()][i.get_y()].val = (char*)" ";
			std::cout << _canvas[i.get_x()][i.get_y()];
		}
		_write_buff.clear();
		_write_buff_offset = 0;
	}

	void Canvas::_init(void)
	{
		_alloc();
		switch (_axis_type) {
		case AXIS_TYPE::UNSIGNED:
			_set_center({ _rows - 1, 0 });
			break;
		case AXIS_TYPE::UNSIGNED_X:
			_set_center({ (_rows / 2) - 1, 0 });
			break;
		case AXIS_TYPE::UNSIGNED_Y:
			_set_center({ _rows - 1, (_cols / 2) - 1 });
			break;
		default: // SIGNED
			_set_center({(_rows / 2) - 1, (_cols / 2) - 1 });
		}
		std::cout << get_center();
	}

	void Canvas::_alloc(void)
	{
		_canvas = new VTerm::dwchar_t* [_rows];
		for (int i = 0; i < _rows; ++i)
			_canvas[i] = new VTerm::dwchar_t[_cols];
	}

	void Canvas::_dealloc(void)
	{
		for (int i = 0; i < _rows; ++i)
			delete[] _canvas[i];
		delete[] _canvas;
	}

	void Canvas::_show_x_axis(Point2D& center)
	{
		char buff[10];
		for (int i = center.get_x(); i <= center.get_x(); ++i)
			for (int j = 0; j < _cols; ++j)
				if (j % 25 == 0) {
					base::itoa(j, buff, 10);
					std::cout << (_canvas[i][j] = { (char*)"|", i, j });
					//std::cout << (_canvas[i][j] = {(char*)buff, i, j } );
				}
				else
					std::cout << (_canvas[i][j] = { (char*)"_", i, j });
	}

	void Canvas::_show_y_axis(Point2D& center)
	{
		char buff[10];
		for (int i = 0; i < _rows; ++i)
			for (int j = center.get_y(); j <= center.get_y(); ++j)
				if (i % (short)floor(28 / _ratio) == 0) {
					base::itoa(j, buff, 10);
					std::cout << (_canvas[i][j] = { (char*)"-", i, j });
				}
				else
					std::cout << (_canvas[i][j] = { (char*)"|", i, j });
	}
	
	void Canvas::_set_center(const Point2D& center)
	{
		_center.set_x(center.get_x());
		_center.set_y(center.get_y());
	}

	short Canvas::_get_ratio(void) const
	{
		return _ratio;
	}
	
	const char* Canvas::_gen_symbol(const std::vector<Point2D>& points, int curr_pos)
	{
		int curr_x = points[curr_pos].get_x();
		int curr_y = points[curr_pos].get_y();
		int prev_x, prev_y, next_x, next_y;
#ifdef _DEVELOPMENT
		//_DEBUG_PRINTF(NORMAL, "%s%d%s%d%s", "{ ", points[curr_pos].y, ", ", points[curr_pos].x, " }");
#endif
		//std::cout << "{ " << points[curr_pos].x << ", " << points[curr_pos].y << " }( " << points[curr_pos].y % _ratio << " )\n";
		switch (points[curr_pos].get_y() % _ratio) {
		case 0:
			return u8"\u2840";
		case 1:
			if (curr_pos > 0) {
				if (points[curr_pos].get_y() == points[curr_pos - 1].get_y())
					return u8"\u2806";
			}
			return u8"\u2804";
		case 2:
			return u8"\u2802";
		default:
			if (curr_pos > 0) {
				if (points[curr_pos].get_y() == points[curr_pos - 1].get_y())
					return "";
			}
			return u8"\u2801";
		}
		// start
		if (curr_pos == 0) {
			// if vector has one element, return a point
			if ((curr_pos + 1) == (int)points.size())
				return ".";
			next_x = points[curr_pos + 1].get_x();
			next_y = points[curr_pos + 1].get_y();
			if (curr_x == next_x) {
				// curr_y > next_y = up
				if (curr_y > next_y) {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u2803";
					case 1:
						return u8"\u2806";
					case 2:
						return u8"\u2844";
					default:
						;
					}
					return u8"\u2844";
				}
				// curr_y < next_y = down
				else {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u2844";
					case 1:
						return u8"\u2844";
					case 2:
						return u8"\u2806";
					default:
						;
					}
					return u8"\u2803";
				}
				// curr_y == next_y
				return u8"\u2809";
			}
			else if (curr_y == next_y) {
				// curr_x < next_x = right
				if (curr_x < next_x) {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u28C0";
					case 1:
						return u8"\u2824";
					case 2:
						return u8"\u2812";
					default:
						;
					}
					return u8"\u2809";
				}
				// curr_x > next_x = left
				else {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u28C0";
					case 1:
						return u8"\u2824";
					case 2:
						return u8"\u2812";
					default:
						;
					}
					return u8"\u2809";
				}
				// curr_x == next_x
				return u8"\u2809";
			}
			else {
				if (curr_x < next_x && curr_y < next_y)
					return u8"\u2836";
				if (curr_x < next_x && curr_y > next_y)
					return u8"\u2814";
				if (curr_x > next_x && curr_y < next_y)
					return u8"\u2836";
				if (curr_x > next_x && curr_y > next_y)
					return u8"\u2814";
			}
		}
		// middle
		else if((curr_pos + 1) < (int)points.size()) {
			prev_x = points[curr_pos - 1].get_x();
			prev_y = points[curr_pos - 1].get_y();
			next_x = points[curr_pos + 1].get_x();
			next_y = points[curr_pos + 1].get_y();
			if (curr_x == next_x) {
				// curr_y > next_y = up
				if (curr_y > next_y) {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u2803";
					case 1:
						return u8"\u2806";
					case 2:
						return u8"\u2844";
					default:
						;
					}
					return u8"\u2844";
				}
				// curr_y < next_y = down
				else {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u2844";
					case 1:
						return u8"\u2844";
					case 2:
						return u8"\u2806";
					default:
						;
					}
					return u8"\u2803";
				}
				// curr_y == next_y
				return u8"\u2809";
			}
			else if (curr_y == next_y) {
				// curr_x < next_x = right
				if (curr_x < next_x) {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u28C0";
					case 1:
						return u8"\u2824";
					case 2:
						return u8"\u2812";
					default:
						;
					}
					return u8"\u2809";
				}
				// curr_x > next_x = left
				else {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u28C0";
					case 1:
						return u8"\u2824";
					case 2:
						return u8"\u2812";
					default:
						;
					}
					return u8"\u2809";
				}
				// curr_x == next_x
				return u8"\u2809";
			}
			else {
				// right - up
				if (curr_x < next_x && curr_y > next_y) {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						//return u8"\u280A";
						break;
					case 1:
						return u8"\u280A";
						break;
					case 2:
						//return u8"\u2860";
					default:
						return u8"\u2814";
					}
				}
				// right - down
				if (curr_x < next_x && curr_y < next_y) {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u280A";
						break;
					case 1:
						break;
					case 2:
						return u8"\u2860";
						//return u8"\u2860";
					default:
						return u8"\u2814";
					}
					/*switch (next_y % _ratio) {
					case 0:
						return u8"\u2884";
					case 1:
						return u8"\u2822";
					case 2:
						return u8"\u2822";
					default:
						return u8"\u2811";
					}*/
				}
				// left - up
				if (curr_x > next_x && curr_y > next_y) {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u2811";
					case 1:
						return u8"\u2822";
					case 2:
						return u8"\u2884";
					default:
						;
					}
					return u8"\u2884";
				}
				// left - down
				if (curr_x > next_x&& curr_y < next_y) {
					// depending on ratio y varies height
					switch (next_y % _ratio) {
					case 0:
						return u8"\u2860";
					case 1:
						return u8"\u2814";
					case 2:
						return u8"\u280A";
					default:
						;
					}
					return u8"\u280A";
				}
			}
		}
		// last
		else {
			prev_x = points[curr_pos - 1].get_x();
			prev_y = points[curr_pos - 1].get_y();
			if (curr_x ==  prev_x && ( curr_y < prev_y || curr_y > prev_y))
				return u8"\u2847";
			else if (curr_y == prev_y && (curr_x < prev_x || curr_x > prev_x)) {
				// depending on ratio y varies height
				switch (curr_y % _ratio) {
				case 0:
					return u8"\u28C0";
				case 1:
					return u8"\u2824";
				case 2:
					return u8"\u2812";
				default:
					;
				}
				return u8"\u2809";
			}
			else {
				if (curr_x < prev_x && curr_y < prev_y)
					return u8"\u2836";
				if (curr_x < prev_x && curr_y > prev_y)
					return u8"\u2814";
			}
		}
		return u8"\u2836";
	}

} // namespace ui

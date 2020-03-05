#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <cstdarg>
#include <stdlib.h>
#include "../ui/drawer.h"
//#include "../base/base.h"

#undef _DEVELOPMENT

namespace ui {

Drawer::Drawer() {}

Drawer::~Drawer() {}

template <typename T>
void Drawer::draw(T obj)
{

}

/*
	Drawer::Drawer(short rows, short cols)
		:_rows(rows), _cols(cols), _ratio(floor(_cols / _rows))
	{
		_init();
	}

	Drawer::Drawer(short rows, short cols, AXIS_TYPE type)
		: _rows(rows), _cols(cols), _ratio(floor(_cols / _rows)), _axis_type(type)
	{
		_init();
	}

	Drawer::~Drawer()
	{
		_dealloc();
	}

	std::ostream& operator<<(std::ostream& out, const Point2D& point)
	{
		return out;
	}

	void Drawer::draw(gfx::Shape2D& shape)
	{
		draw(shape.get_points());//, shape.get_color());
	}

	void Drawer::draw(const std::vector<Point2D>& points)
	{
		for (int i = 0; i < (int)points.size(); ++i)
			put_char(_gen_symbol(points, i), points[i].x, points[i].y);
		print();
		// move cursor to the end
		dwchar_t end = { (char*)"", _rows - 1, _cols - 1 };
		std::cout << end;
	}

	void Drawer::draw(const std::vector<Point2D>& points, Color color)
	{
		char sym[22];
		for (int i = 0; i < (int)points.size(); ++i) {
			base::strcat_all(sym, 22, "sdcdcdcs", "\x1B[38;2;", color.r, ';', color.g, ';', color.b, 'm', _gen_symbol(points, i));
			put_char(sym, points[i].x, points[i].y);
		}
		print();
		// move cursor to the end
		dwchar_t end = { (char*)"", _rows - 1, _cols - 1 };
		std::cout << end;
	}

	void Drawer::draw(gfx::Shape2D& s1, gfx::Shape2D& s2, gfx::Shape2D& s3)
	{*/
		/*void (Drawer::* dw)(gfx::Shape2D&) = &Drawer::draw;
		std::thread t1(dw, s1);
		std::thread t2(dw, s2);
		std::thread t3(dw, s3);

		t1.join();
		t2.join();
		t3.join();*/
/*	}

	void Drawer::put_char(const char* s, int x, int y)
	{
		Point2D center = get_center();
		// adjust y-axis to x-axis
		Point2D coords = { (center.x - (short)floor(y / _ratio)), center.y + x };
		_write_buff.push_back(coords);
		_canvas[coords.x][coords.y] = { (char*)s, coords.x, coords.y };
	}

	void Drawer::print(void)
	{
		for (auto i = _write_buff.begin() + _write_buff_offset; i != _write_buff.end(); ++i) {
#ifdef _DEVELOPMENT
			_DEBUG_PRINTF(NORMAL, "%s%d%s%d%s", "{ ", i->y, ", ", i->x, " }");
#endif
			std::cout << _canvas[i->x][i->y];
			std::this_thread::sleep_for(std::chrono::milliseconds(0));
		}
		// reset color - apply text bright
		std::cout << "\x1B[0m" << "\x1B[1m";
		_write_buff_offset += _write_buff.size() - _write_buff_offset;
	}

	void Drawer::flush(void)
	{
		for (const auto& i : _write_buff) {
			_canvas[i.x][i.y].val = (char*)" ";
			std::cout << _canvas[i.x][i.y];
		}
		_write_buff.clear();
		_write_buff_offset = 0;
	}

	void Drawer::_init(void)
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

	void Drawer::_alloc(void)
	{
		_canvas = new VTerm::dwchar_t* [_rows];
		for (int i = 0; i < _rows; ++i)
			_canvas[i] = new VTerm::dwchar_t[_cols];
	}

	void Drawer::_dealloc(void)
	{
		for (int i = 0; i < _rows; ++i)
			delete[] _canvas[i];
		delete[] _canvas;
	}
	
	const char* Drawer::_gen_symbol(const std::vector<Point2D>& points, int curr_pos)
	{
		int curr_x = points[curr_pos].x;
		int curr_y = points[curr_pos].y;
		int prev_x, prev_y, next_x, next_y;
#ifdef _DEVELOPMENT
		//_DEBUG_PRINTF(NORMAL, "%s%d%s%d%s", "{ ", points[curr_pos].y, ", ", points[curr_pos].x, " }");
#endif
		//std::cout << "{ " << points[curr_pos].x << ", " << points[curr_pos].y << " }( " << points[curr_pos].y % _ratio << " )\n";
		switch (points[curr_pos].y % _ratio) {
		case 0:
			return u8"\u2840";
		case 1:
			if (curr_pos > 0) {
				if (points[curr_pos].y == points[curr_pos - 1].y)
					return u8"\u2806";
			}
			return u8"\u2804";
		case 2:
			return u8"\u2802";
		default:
			if (curr_pos > 0) {
				if (points[curr_pos].y == points[curr_pos - 1].y)
					return "";
			}
			return u8"\u2801";
		}
		// start
		if (curr_pos == 0) {
			// if vector has one element, return a point
			if ((curr_pos + 1) == (int)points.size())
				return ".";
			next_x = points[curr_pos + 1].x;
			next_y = points[curr_pos + 1].y;
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
			prev_x = points[curr_pos - 1].x;
			prev_y = points[curr_pos - 1].y;
			next_x = points[curr_pos + 1].x;
			next_y = points[curr_pos + 1].y;
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
					}*/
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
				/*}
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
			prev_x = points[curr_pos - 1].x;
			prev_y = points[curr_pos - 1].y;
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
	}*/

} // namespace ui

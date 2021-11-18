#include "graphic.h"
#include <cmath>

#define PI 3.14159265

namespace ui {

Graphic::Graphic(short dwable_w, short dwable_h)
	: _dwable_w(dwable_w), _dwable_h(dwable_h)
{}

Graphic::Graphic(void *context, short dwable_w, short dwable_h)
	: _dwable_w(dwable_w), _dwable_h(dwable_h)
{}

Graphic::~Graphic() {}

void Graphic::draw(const char *s, int x, int y)
{
    put(s, x, y);
}

void Graphic::draw(const std::vector<Point2D>& points)
{
    // _gen_symbol(points);
    put_buffer(points);
    std::string s;
    for (auto i : get_screen_buffer()) s += (i ? u8"\u2550" : " ");
    std::cout << s << std::flush;
    set_cursor_pos(1, 1);
}

/*
void Graphic::draw(const std::vector<Point2D>& points)
{
    // _gen_symbol(points);
    put_buffer(points);
    std::string s;
    for (auto i : get_screen_buffer()) s += (i ? u8"\u2550" : " ");
    std::cout << s;
    set_cursor_pos(1, 1);
}

void Graphic::draw(const std::vector<Point2D>& points)
{
    // _gen_symbol(points);
    put_buffer(points);
    std::string shape("");
    // for (auto i : get_screen_buffer()) s += (i ? u8"\u2550" : " ");
    auto sb = get_screen_buffer(points);
    for (int i = 0; i < sb.size(); ++i) {
        set_cursor_pos(points[i].get_x(), points[i].get_y());
        std::cout << (sb[i] ? u8"\u2550" : " ");
        // std::cout << sb[points] << std::flush;
    }
    set_cursor_pos(1, 1);

}
*/

void Graphic::draw(const Shape2D& shape)
{
    put_buffer(shape.get_bounds());
    std::string s;
    for (auto i : get_screen_buffer()) s += (i ? u8"\u2550" : " ");
    std::cout << s;
    set_cursor_pos(1, 1);
}

void Graphic::erase(const std::vector<Point2D>& points)
{
    erase_buffer(points);
    std::string s;
    for (auto i : get_screen_buffer()) s += (i ? "." : " ");
    std::cout << s << std::flush;
    set_cursor_pos(1, 1);
}

void Graphic::erase(const Shape2D& shape)
{
    erase_buffer(shape.get_bounds());
    std::string s;
    for (auto i : get_screen_buffer()) s += (i ? "." : " ");
    std::cout << s << std::flush;
    set_cursor_pos(1, 1);
}

const char* Graphic::_gen_symbol(const std::vector<Point2D>& points)
{
    for (int i = 0; i < points.size() - 1; ++i)
        std::cout << atan2(points[i + 1].get_y() - points[i].get_y(), points[i + 1].get_x() - points[i].get_x()) * 180 / PI << std::endl;
}

} // namespace ui


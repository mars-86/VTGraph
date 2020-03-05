/*#include "graphic.h"

namespace ui {

Graphic::Graphic() {}

Graphic::~Graphic() {}

template <typename T>
void Graphic::draw_rect(T** drawable, const Rect& rect, Color color)
{
	//_draw(fm, rect.get_bounds());
	for (auto& i : rect.get_bounds())
		drawable[i.get_x()][i.get_y()].val = (char*)"\u2550";

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			std::cout << drawable[i][j].val;
}

void Graphic::fill_rect(const Rect& rect, Color color)
{

}

void Graphic::_draw(Frame& fm, const std::vector<Point2D> points)
{
	//dwchar_t dwb = const_cast<dwchar_t&>(drawable);
	std::cout << "ACA" << std::endl;
	for (auto& i : points)
		fm._drawable[i.get_x()][i.get_y()].val = (char*)"\u2550";

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			std::cout << fm._drawable[i][j].val;
}

} // namespace ui
*/

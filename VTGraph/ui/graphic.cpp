#include "graphic.h"

namespace ui {

Graphic::Graphic(short dwable_w, short dwable_h) 
	: _dwable_w(dwable_w), _dwable_h(dwable_h)
{
	_init();
}

Graphic::~Graphic()
{
	_dealloc();
}

void Graphic::draw_rect(const Rect& rect, Color color)
{
	for (auto& i : rect.get_bounds())
		std::cout << (_drawable[i.get_y() - 1][i.get_x() - 1] = { (char*)u8"\u2550", i.get_x(), i.get_y() });
}

void Graphic::fill_rect(const Rect& rect, Color color)
{
	//std::cout << rect.get_origin().get_y() << rect.get_origin().get_x();
	//std::cout << " " << rect.get_origin().get_y() + rect.get_height() << rect.get_origin().get_x() + rect.get_width();
	for (int i = rect.get_origin().get_y() + 1; i < rect.get_origin().get_y() + rect.get_height(); ++i)
		for (int j = rect.get_origin().get_x() + 1; j < rect.get_origin().get_y() + rect.get_width() - 1; ++j)
			std::cout << (_drawable[i - 1][j - 1] = { (char*)" ", j, i });
	//std::getchar();
}

void Graphic::draw_component(const UIComponent& uic)
{
	std::cout << "\x1B[107m";
	std::cout << "\x1B[30m";
	Rect rect(_curr_col, _curr_row, uic.get_width(), uic.get_height());
	fill_rect(rect, { 150, 150, 150 });
	draw_rect(rect, { 150, 150, 150 });
	_curr_row = (rect.get_width() == _dwable_w) ? _curr_row + rect.get_height() : _curr_row;
	_curr_col = (rect.get_width() == _dwable_w) ? 1 : _curr_col + rect.get_width();
}

void Graphic::_init(void)
{
	//_drawer = new Graphic(_drawable);
	//_drawer = new Graphic();
	_alloc();
}

void Graphic::_alloc(void)
{
	_drawable = new dwchar_t* [_dwable_h];
	for (int i = 0; i < _dwable_h; ++i)
		_drawable[i] = new dwchar_t[_dwable_w];
}

void Graphic::_dealloc(void)
{
	for (int i = 0; i < _dwable_h; ++i)
		delete[] _drawable[i];
	delete[] _drawable;
	//delete _drawer;
}

//void Graphic::_draw(const std::vector<Point2D> points)
//{
	//dwchar_t dwb = const_cast<dwchar_t&>(drawable);
	/*std::cout << "ACA" << std::endl;
	for (auto& i : points)
		fm._drawable[i.get_x()][i.get_y()].val = (char*)"\u2550";

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			std::cout << fm._drawable[i][j].val;*/
//}

} // namespace ui


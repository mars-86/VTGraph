#include "graphic.h"

namespace ui {

Graphic::Graphic(short dwable_w, short dwable_h) 
	: _dwable_w(dwable_w), _dwable_h(dwable_h)
{
	_init();
	std::cout << "\x1B[107m";
	std::cout << "\x1B[30m";
}

Graphic::~Graphic()
{
	_dealloc();
}

void Graphic::draw_rect(const Rect& rect, const Color& color)
{
	char *sym;
	std::vector<Point2D> bounds = rect.get_bounds();
	for (auto i = bounds.begin() + 1; i != bounds.end(); ++i) {
		sym = (i->get_y() == (i - 1)->get_y()) ? (char*)u8"\u2550" : (char*)u8"\u2551";
		_draw_at(sym, i->get_x(), i->get_y());
	}
	Point2D ori = rect.get_origin();
	_top_left_edge(ori, rect);
	_top_right_edge(ori, rect);
	_bottom_left_edge(ori, rect);
	_bottom_right_edge(ori, rect);
}

void Graphic::fill_rect(const Rect& rect, const Color& color)
{
	//std::cout << rect.get_origin().get_y() << rect.get_origin().get_x();
	//std::cout << " " << rect.get_origin().get_y() + rect.get_height() << rect.get_origin().get_x() + rect.get_width();
	for (int i = rect.get_origin().get_y() + 1; i < rect.get_origin().get_y() + rect.get_height(); ++i)
		for (int j = rect.get_origin().get_x() + 1; j < rect.get_origin().get_x() + rect.get_width(); ++j)
			_draw_at((char*)" ", j, i);
	//std::getchar();
}

void Graphic::draw_component(const Container& c)
{
	//Rect rect(_curr_col, _curr_row, c.get_width(), c.get_height());
	//fill_rect(rect, { 150, 150, 150 });
	//draw_rect(rect, { 150, 150, 150 });
	for (auto& i : c.get_childs()) {
		if (i.second.get_type() == "EuclideanSpace")
			draw_component(static_cast<EuclideanSpace&>(i.second));
		if (i.second.get_type() == "TitleBar")
			draw_component(static_cast<TitleBar&>(i.second));
		if (i.second.get_type() == "Table")
			draw_component(static_cast<Table&>(i.second));
	}
}

void Graphic::draw_component(const EuclideanSpace& espc)
{
	Rect rect(_curr_col, _curr_row, espc.get_width(), espc.get_height());
	fill_rect(rect, { 150, 150, 150 });
	draw_rect(rect, { 150, 150, 150 });
	// Draw e context
	Point2D ori = rect.get_origin();
	int curr_row = ori.get_y() + 1, curr_col = ori.get_x() + 1;
	if (espc.get_context() == "2D") {
		for (int i = 0; i < rect.get_height() - 1; ++i, ++curr_row)
			_draw_at((char*)u8"\u2502", curr_col + ((rect.get_width() - 1) / 2), curr_row);
		curr_row = ori.get_y() + 1;
		for (int i = 0; i < rect.get_width() - 1; ++i, ++curr_col)
			_draw_at((char*)u8"\u2500", curr_col, curr_row + ((rect.get_height() - 1) / 2));
		curr_col = ori.get_x() + 1;
		_draw_at((char*)u8"\u253C", curr_col + ((rect.get_width() - 1) / 2), curr_row + ((rect.get_height() - 1) / 2));
	}
	_set_row_col(rect);
}

void Graphic::draw_component(const Table& tab)
{
	Rect rect(_curr_col, _curr_row, tab.get_width(), tab.get_height());
	fill_rect(rect, { 150, 150, 150 });
	draw_rect(rect, { 150, 150, 150 });
	// Draw table
	Point2D ori = rect.get_origin();
	const std::vector<std::vector<std::string>> t = tab.get_table();
	int curr_row = ori.get_y() + 1, curr_col = ori.get_x() + 1;
	for (uint32_t i = 0; i < t.size(); ++i) {
		for (uint32_t j = 0; j < t[i].size() && t[i].size() <= t[0].size(); ++j) {
			// TODO: change hardcoded offset
			_draw_at((char*)t[i][j].c_str(), (curr_col + 4), curr_row);
			_draw_at((char*)u8"\u2502", (curr_col + 9), curr_row);
			curr_col += 10;
		}
		++curr_row, curr_col = ori.get_x() + 1;
		for (int k = 1; k < rect.get_width(); ++k)
			_draw_at((char*)((k % 10 == 0) ? u8"\u253C" : u8"\u2500"), (curr_col + k - 1), curr_row);
		++curr_row;
	}
	_set_row_col(rect);
}

void Graphic::draw_component(const TitleBar& tbar)
{
	Rect rect(_curr_col, _curr_row, tbar.get_width(), tbar.get_height());
	fill_rect(rect, { 150, 150, 150 });
	draw_rect(rect, { 150, 150, 150 });
	_set_row_col(rect);
}

/*
void Graphic::draw_component(const UIComponent& uic)
{
	std::cout << "\x1B[107m";
	std::cout << "\x1B[30m";
	//std::cout << dynamic_cast<Table> (uic);
	std::string uic_type = uic.get_type();
	Rect rect(_curr_col, _curr_row, uic.get_width(), uic.get_height());
	fill_rect(rect, { 150, 150, 150 });
	draw_rect(rect, { 150, 150, 150 });
	if (uic_type == "Table") {
		UIComponent tab = const_cast<UIComponent&>(uic);
		Table t = (Table&)tab;// dynamic_cast<Table&>(tab);
		std::cout << t.get_table().size();
		std::getchar();
		draw_component(t, rect);
	}
	_curr_row = (rect.get_width() == _dwable_w) ? _curr_row + rect.get_height() : _curr_row;
	_curr_col = (rect.get_width() == _dwable_w) ? 1 : _curr_col + rect.get_width();
}*/

void Graphic::_set_row_col(const Rect& drawed)
{
	_curr_row = (drawed.get_width() == _dwable_w) ? _curr_row + drawed.get_height() : _curr_row;
	_curr_col = (drawed.get_width() == _dwable_w) ? 1 : _curr_col + drawed.get_width();
}

void Graphic::_draw_at(char *str, short x, short y)
{
	std::cout << (_drawable[y - 1][x - 1] = { str, x, y });
}

void Graphic::_draw_at(char* str, int x, int y)
{
	std::cout << (_drawable[y - 1][x - 1] = { str, x, y });
}

void Graphic::_top_left_edge(const Point2D& ori, const Rect& rect)
{
	if (ori.get_y() == 1 && ori.get_x() == 1)
		_draw_at((char*)u8"\u2554", ori.get_x(), ori.get_y());
	else if (ori.get_y() > 1 && ori.get_x() == 1)
		_draw_at((char*)u8"\u2560", ori.get_x(), ori.get_y());
	else
		_draw_at((char*)u8"\u2566", ori.get_x(), ori.get_y());
}

void Graphic::_top_right_edge(const Point2D& ori, const Rect& rect)
{
	if (ori.get_y() == 1 && (ori.get_x() + rect.get_width() - 1 == _dwable_w))
		_draw_at((char*)u8"\u2557", ori.get_x() + rect.get_width() , ori.get_y());
	else if (ori.get_y() > 1 && (ori.get_x() + rect.get_width() - 1 == _dwable_w))
		_draw_at((char*)u8"\u2563", ori.get_x() + rect.get_width() , ori.get_y());
	else
		_draw_at((char*)u8"\u2566", ori.get_x() + rect.get_width() , ori.get_y());
}

void Graphic::_bottom_left_edge(const Point2D& ori, const Rect& rect)
{
	if (ori.get_x() == 1)
		_draw_at((char*)u8"\u255A", ori.get_x(), ori.get_y() + rect.get_height());
	else if ((ori.get_y() + rect.get_height() - 1 < _dwable_h) && (ori.get_x() > 1))
		_draw_at((char*)u8"\u2569", ori.get_x(), ori.get_y() + rect.get_height());
	else
		_draw_at((char*)u8"\u2569", ori.get_x(), ori.get_y() + rect.get_height());
}

void Graphic::_bottom_right_edge(const Point2D& ori, const Rect& rect)
{
	if (ori.get_x() + rect.get_width() - 1 == _dwable_w)
		_draw_at((char*)u8"\u255D", ori.get_x() + rect.get_width(), ori.get_y() + rect.get_height());
	else if ((ori.get_y() + rect.get_height() - 1 < _dwable_h) && (ori.get_x() + rect.get_width() - 1 < _dwable_w))
		_draw_at((char*)u8"\u2563", ori.get_x() + rect.get_width(), ori.get_y() + rect.get_height());
	else
		_draw_at((char*)u8"\u2569", ori.get_x() + rect.get_width(), ori.get_y() + rect.get_height());
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


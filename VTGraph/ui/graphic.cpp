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

void Graphic::draw_rect(const Rect& rect, Color color)
{
	char *sym;
	std::vector<Point2D> bounds = rect.get_bounds();
	for (auto i = bounds.begin() + 1; i != bounds.end(); ++i) {
		sym = (i->get_y() == (i - 1)->get_y()) ? (char*)u8"\u2550" : (char*)u8"\u2551";
		std::cout << (_drawable[i->get_y() - 1][i->get_x() - 1] = { sym, i->get_x(), i->get_y() });
	}

	Point2D ori = rect.get_origin();
	// TOP LEFT
	if (ori.get_y() == 1 && ori.get_x() == 1)
		std::cout << (_drawable[ori.get_y() - 1][ori.get_x() - 1] = { (char*)u8"\u2554", ori.get_x(), ori.get_y() });
	else if (ori.get_y() > 1 && ori.get_x() == 1)
		std::cout << (_drawable[ori.get_y() - 1][ori.get_x() - 1] = { (char*)u8"\u2560", ori.get_x(), ori.get_y() });
	else
		std::cout << (_drawable[ori.get_y() - 1][ori.get_x() - 1] = { (char*)u8"\u2566", ori.get_x(), ori.get_y() });
	// TOP RIGHT
	if (ori.get_y() == 1 && (ori.get_x() + rect.get_width() - 1 == _dwable_w))
		std::cout << (_drawable[ori.get_y() - 1][ori.get_x() + rect.get_width() - 1] = { (char*)u8"\u2557", ori.get_x() + rect.get_width() , ori.get_y() });
	else if (ori.get_y() > 1 && (ori.get_x() + rect.get_width() - 1 == _dwable_w))
		std::cout << (_drawable[ori.get_y() - 1][ori.get_x() + rect.get_width() - 1] = { (char*)u8"\u2563", ori.get_x() + rect.get_width() , ori.get_y() });
	else
		std::cout << (_drawable[ori.get_y() - 1][ori.get_x() + rect.get_width() - 1] = { (char*)u8"\u2566", ori.get_x() + rect.get_width() , ori.get_y() });
	// BOTTOM LEFT
	if (ori.get_x() == 1)
		std::cout << (_drawable[ori.get_y() + rect.get_height() - 1][ori.get_x() - 1] = { (char*)u8"\u255A", ori.get_x(), ori.get_y() + rect.get_height() });
	else if ((ori.get_y() + rect.get_height() - 1 < _dwable_h) && (ori.get_x() > 1))
		std::cout << (_drawable[ori.get_y() + rect.get_height() - 1][ori.get_x() - 1] = { (char*)u8"\u2569", ori.get_x(), ori.get_y() + rect.get_height() });
	else
		std::cout << (_drawable[ori.get_y() + rect.get_height() - 1][ori.get_x() - 1] = { (char*)u8"\u2569", ori.get_x(), ori.get_y() + rect.get_height() });
	// BOTTOM RIGHT
	if (ori.get_x() + rect.get_width() - 1 == _dwable_w)
		std::cout << (_drawable[ori.get_y() + rect.get_height() - 1][ori.get_x() + rect.get_width() - 1] = { (char*)u8"\u255D", ori.get_x() + rect.get_width(), ori.get_y() + rect.get_height() });
	if ((ori.get_y() + rect.get_height() - 1 < _dwable_h) && (ori.get_x() + rect.get_width() - 1 < _dwable_w))
		std::cout << (_drawable[ori.get_y() + rect.get_height() - 1][ori.get_x() + rect.get_width() - 1] = { (char*)u8"\u2563", ori.get_x() + rect.get_width(), ori.get_y() + rect.get_height() });
	else
		std::cout << (_drawable[ori.get_y() + rect.get_height() - 1][ori.get_x() + rect.get_width() - 1] = { (char*)u8"\u2569", ori.get_x() + rect.get_width(), ori.get_y() + rect.get_height() });
}

void Graphic::fill_rect(const Rect& rect, Color color)
{
	//std::cout << rect.get_origin().get_y() << rect.get_origin().get_x();
	//std::cout << " " << rect.get_origin().get_y() + rect.get_height() << rect.get_origin().get_x() + rect.get_width();
	for (int i = rect.get_origin().get_y() + 1; i < rect.get_origin().get_y() + rect.get_height(); ++i)
		for (int j = rect.get_origin().get_x() + 1; j < rect.get_origin().get_x() + rect.get_width(); ++j)
			std::cout << (_drawable[i - 1][j - 1] = { (char*)" ", j, i });
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
			_draw_at((char*)t[i][j].c_str(), (curr_col + 4), curr_row);
			_draw_at((char*)u8"\u2502", (curr_col + 9), curr_row);
			curr_col += 10;
		}
		++curr_row, curr_col = ori.get_x() + 1;
		for (int k = 1; k < rect.get_width(); ++k)
			_draw_at((char*)((k % 10 == 0) ? u8"\u253C" : u8"\u2500"), (curr_col + k - 1), curr_row);
		++curr_row;
	}
	// draw_component(tab, rect);
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

void Graphic::draw_component(const Table& tab, const Rect& rect) {
	Point2D ori = rect.get_origin();
	const std::vector<std::vector<std::string>> data = tab.get_table();
	int c = 0;
	//for ()
	set_cursor_pos((short)(ori.get_x() + 1 + 4), (short)(ori.get_y() + 1));
	std::cout << "X";
	set_cursor_pos((short)(ori.get_x() + 1 + 9), (short)(ori.get_y() + 1));
	std::cout << u8"\u2502";
	set_cursor_pos((short)(ori.get_x() + 1 + 9 + 5), (short)(ori.get_y() + 1));
	std::cout << "Y";
	set_cursor_pos((short)(ori.get_x() + 1 + 19), (short)(ori.get_y() + 1));
	std::cout << u8"\u2502";
	set_cursor_pos((short)(ori.get_x() + 1 + 19 + 5), (short)(ori.get_y() + 1));
	std::cout << "Z";
	for (int i = 1; i < 30; ++i) {
		set_cursor_pos((short)(ori.get_x() + i), (short)(ori.get_y() + 2));
		std::cout << ((i % 10 == 0) ? u8"\u253C" : u8"\u2500");
	}
	for (int j = 3; j < 29; ++j) {
		set_cursor_pos((short)(ori.get_x() + 1 + 4), (short)(ori.get_y() + j));
		std::cout << c++;
		set_cursor_pos((short)(ori.get_x() + 1 + 9), (short)(ori.get_y() + j));
		std::cout << u8"\u2502";
		set_cursor_pos((short)(ori.get_x() + 1 + 9 + 5), (short)(ori.get_y() + j));
		std::cout << c++;
		set_cursor_pos((short)(ori.get_x() + 1 + 19), (short)(ori.get_y() + j));
		std::cout << u8"\u2502";
		set_cursor_pos((short)(ori.get_x() + 1 + 19 + 5), (short)(ori.get_y() + j));
		std::cout << c++;
		j++;
		for (int i = 1; i < 30; ++i) {
			set_cursor_pos((short)(ori.get_x() + i), (short)(ori.get_y() + j));
			std::cout << ((i % 10 == 0) ? u8"\u253C" : u8"\u2500");
		}
	}
	std::cout << data.size();
	std::getchar();
	for (uint32_t i = 0; i < data.size(); ++i) {
		auto row = &data[i];
		for (auto k = row->begin(); k != row->end(); ++k)
			_draw_at((char*)"HOLA", 10, 10);
	}
		//std::cout << (_drawable[ori.get_y()][ori.get_x()] = { (char*)"Naada", ori.get_x() + 1, ori.get_y() + 1 });
}

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


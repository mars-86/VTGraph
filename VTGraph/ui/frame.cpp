#include "frame.h"

namespace ui {

Frame::Frame(short width, short height)
	: Container( {width, height} ), _app_name("APP")
{
	_drawer = new Graphic(width, height);
}

Frame::Frame(std::string app_name, short width, short height)
	: Container({ width, height }), _app_name(app_name)
{
	_drawer = new Graphic(width, height);
}

Frame::~Frame()
{
	delete _drawer;
}

/*
void Template::add_element(Element& el)
{
	//_set_element(el);
	//_set_threshold(_curr_row, _curr_col, _curr_row + el.get_size().rows - 1, _curr_col + el.get_size().cols - 1);
	//_el.insert(std::pair<short, _elem&>(_curr_col, {el, {_curr_row, _curr_col, _curr_row + el.get_size().rows - 1, _curr_col + el.get_size().cols - 1}}));
	for (int i = _curr_row; i <= _curr_row; ++i) {
		std::cout << "\x1B[" << i << ";" << _curr_col << "H" << u8"\u2554";
		for (int j = _curr_col + 1; j < _curr_col + el.get_size().cols; ++j)
			std::cout << "\x1B[" << i << ";" << j << "H" << u8"\u2550" << std::flush;
		std::cout << "\x1B[" << i << ";" << _curr_col + el.get_size().cols - 1 << "H" << u8"\u2557" << std::flush;
	}
	for (int i = _curr_row + 1; i < _curr_row + el.get_size().rows - 1; ++i) {
		std::cout << "\x1B[" << i << ";" << _curr_col << "H" << u8"\u2551" << std::flush;
		std::cout << "\x1B[" << i << ";" << _curr_col + el.get_size().cols - 1 << "H" << u8"\u2551" << std::flush << std::endl;
	}
	for (int i = _curr_row + el.get_size().rows - 1; i <= _curr_row + el.get_size().rows - 1; ++i) {
		std::cout << "\x1B[" << i << ";" << _curr_col << "H" << u8"\u255A" << std::flush;
		for (int j = _curr_col + 1; j < _curr_col + el.get_size().cols - 1; ++j)
			std::cout << "\x1B[" << i << ";" << j << "H" << u8"\u2550" << std::flush;
		std::cout << "\x1B[" << i << ";" << _curr_col + el.get_size().cols - 1 << "H" << u8"\u255D" << std::flush;
	}
	_curr_col = (el.get_size().cols == get_size().cols) ? 1 : _curr_col + el.get_size().cols + 1;
	if (_curr_col == 1) _curr_row += el.get_size().rows;
}*/

void Frame::visible(void)
{
	// for (auto& i : _child)
    //  _drawer->draw_component(i.second);
	// _drawer->draw_component(*this);
	// std::string a_name = get_app_name();
	// _drawer->_draw_at((char*)a_name.c_str(), (get_max_width() / 2) - (get_app_name().size() / 2), 1);
}

const short Frame::get_max_width(void) const
{
	return this->get_width();
}

const short Frame::get_max_height(void) const
{
	return this->get_height();
}

void Frame::set_app_name(std::string app_name)
{
	_app_name = app_name;
}

const std::string& Frame::get_app_name(void) const
{
	return _app_name;
}

void Frame::_draw(const UIComponent& uic)
{
	//_drawer->draw_rect(Rect(_curr_col, _curr_row, uic.get_size().cols, uic.get_size().rows), { 0, 0, 0 });
	// Graphics.draw_rect();
	//std::cout << uic.get_size().cols << std::endl;

/*
	Rect rect(_curr_col, _curr_row, uic.get_width(), uic.get_height(), { 150, 150, 150 });
	dwchar_t dwch;
	for (auto& i : rect.get_bounds()) {
		std::cout << (_drawable[i.get_y() - 1][i.get_x() - 1] = { (char*)u8"\u2550", i.get_x(), i.get_y() });
		//dwch = { (char*)u8"\u2550", i.get_x() , i.get_y() };
		//std::cout << _drawable[i.get_y() - 1][i.get_x() - 1];
	}
	_curr_row = (rect.get_width() == this->get_width()) ? _curr_row + rect.get_height() : _curr_row;
	_curr_col = (rect.get_width() == this->get_width()) ? 1 : _curr_col + rect.get_width();
*/


/*
	for (int i = 0; i < uic.get_size().cols; ++i)
		for (int j = 0; j < uic.get_size().rows; ++j)
			std::cout << _drawable[i][j];*/
	/*std::cout << uic.get_size().cols << std::endl;*/

	/*for( int i = 0; i < uic.get_size().rows; ++i )
		for( int j = 0; j < uic.get_size().cols; ++j )
			std::cout << ".";*/
	//_drawer->draw(el);
}

/*void VTContainer::_set_threshold(short row_ini, short col_ini, short row_max, short col_max)
{
	elem.row_ini = row_ini;
	elem.col_ini = col_ini;
	elem.row_max = row_max;
	elem.col_max = col_max;
}*/

} // namespace ui

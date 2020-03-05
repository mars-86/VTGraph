#include "frame.h"

namespace ui {

Frame::Frame(short width, short height)
	: Container( {width, height} )
{
	_init();
}

Frame::~Frame()
{
	_dealloc();
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
	for (auto& i : _child)
		_draw(i.second);
}

const short Frame::get_max_width(void) const
{
	return get_size().cols;
}

const short Frame::get_max_height(void) const
{
	return get_size().rows;
}

void Frame::_draw(const UIComponent& uic)
{
	//_drawer->draw_rect(Rect(_curr_col, _curr_row, uic.get_size().cols, uic.get_size().rows), { 0, 0, 0 });
	// Graphics.draw_rect();
	//std::cout << uic.get_size().cols << std::endl;
	Rect rect(1, 1, 2, 80);
	dwchar_t dwch;
	for (auto& i : rect.get_bounds()) {
		//_drawable[i.get_x() - 1][i.get_y() - 1] = { (char*)"\u2550", i.get_x() - 1, i.get_y() - 1 };
		dwch = { (char*)"\u2550", i.get_x() , i.get_y() };
		std::cout << dwch;

	}
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


void Frame::_init(void)
{
	//_drawer = new Graphic(_drawable);
	//_drawer = new Graphic();
	_alloc();
}

void Frame::_alloc(void)
{
	_drawable = new dwchar_t* [_size.rows];
	for (int i = 0; i < _size.rows; ++i)
		_drawable[i] = new dwchar_t[_size.cols];
}

void Frame::_dealloc(void)
{
	for (int i = 0; i < _size.rows; ++i)
		delete[] _drawable[i];
	delete[] _drawable;
	//delete _drawer;
}

/*void VTContainer::_set_threshold(short row_ini, short col_ini, short row_max, short col_max)
{
	elem.row_ini = row_ini;
	elem.col_ini = col_ini;
	elem.row_max = row_max;
	elem.col_max = col_max;
}*/

} // namespace ui

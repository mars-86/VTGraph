#include "titlebar.h"

namespace ui {

TitleBar::TitleBar(std::string title, short width, POSITION position)
	: Bar({ width, 2 }), _title(title)
{
	Bar::_set_type("TitleBar");
}

TitleBar::~TitleBar() {}

void TitleBar::set_title(const std::string title)
{
	_title = title;
}

const std::string TitleBar::get_title() const
{
	return _title;
}

} // namespace ui

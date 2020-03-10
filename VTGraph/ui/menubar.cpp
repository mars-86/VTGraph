#include "menubar.h"

namespace ui {

MenuBar::MenuBar(short width, POSITION position)
	: Bar({ width, 2 })
{
	Bar::_set_type("MenuBar");
}

MenuBar::~MenuBar() {}

void MenuBar::add_menu(const Menu& menu)
{
	_child.push_back(menu);
}

const std::vector<Menu>& MenuBar::get_menu(void) const
{
	return _child;
}

} // namespace ui

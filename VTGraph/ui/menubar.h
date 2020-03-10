#ifndef UI_MENU_BAR_H
#define UI_MENU_BAR_H
#pragma once

#include <vector>
#include "bar.h"
#include "menu.h"

namespace ui {

class MenuBar : public Bar {
public:
	MenuBar(short width, POSITION position);
	~MenuBar();
	void add_menu(const Menu& menu);
	const std::vector<Menu>& get_menu(void) const;
	
	void on_click(void) {};
private:
	std::vector<Menu> _child;
};

}

#endif // !UI_MENU_BAR_H

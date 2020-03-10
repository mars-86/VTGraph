#ifndef UI_MENU_H
#define UI_MENU_H
#pragma once

#include <string>
#include <vector>
#include "ui_component.h"
#include "menu_item.h"

namespace ui {

class Menu {
public:
	Menu(std::string name, const std::vector<MenuItem>& items)
		: _name(name), _child(items) {}
	~Menu() {}
	
	void set_name(const std::string name) { _name = name; }
	const std::string& get_name(void) const { return _name; }
private:
	std::string _name;
	std::vector<MenuItem> _child;
};

}

#endif // !UI_MENU_H

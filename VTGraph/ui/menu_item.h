#ifndef UI_MENU_ITEM_H
#define UI_MENU_ITEM_H
#pragma once

#include "item.h"

namespace ui {

class MenuItem : public Item {
public:
	MenuItem(std::string name) : _name(name) {}
	~MenuItem() {}
	
	void set_name(const std::string name) { _name = name; }
	const std::string& get_name(void) const { return _name; }
private:
	std::string _name;
};

}

#endif // !UI_MENU_ITEM_H

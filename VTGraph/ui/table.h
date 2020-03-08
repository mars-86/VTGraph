#ifndef UI_TABLE_H
#define UI_TABLE_H
#pragma once

#include <vector>
#include <string>
#include "ui_component.h"

namespace ui {

class Table : public UIComponent {
public:
	Table(std::vector<std::string>& headers);
	Table(std::vector<std::string>& headers, std::vector<std::vector<std::string>>& data);
	Table(short height, std::vector<std::string>& headers, std::vector<std::vector<std::string>>& data);
	Table(short width, short height, std::vector<std::string>& headers, std::vector<std::vector<std::string>>& data);
	//Bar(const ComponentSize& size, const POSITION position) : UIComponent((size, position) {}
	~Table();
	void add_row(const std::vector<std::string>& row);
	bool is_table(void) const;
private:
	short _rows, _cols;
	std::vector<std::vector<std::string>> _table;
};

}

#endif // !UI_TABLE_H

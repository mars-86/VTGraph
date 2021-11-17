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
	~Table();
	void add_row(const std::vector<std::string>& row);
	bool is_table(void) const;
	short get_col_width(void) const;
	const std::vector<std::vector<std::string>>& get_table(void) const;
	
	void on_click(void) {};
private:
	short _rows, _cols, _row_height = 1, _col_width = 10;
	std::vector<std::vector<std::string>> _table;
};

}

#endif // !UI_TABLE_H

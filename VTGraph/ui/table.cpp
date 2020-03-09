#include "table.h"

namespace ui {

/*Table::Table(short rows, short cols)
	: UIComponent( {(short)(cols * 2), rows} ), _rows(rows), _cols(cols)
{

}*/

Table::Table(std::vector<std::string>& headers)
	: UIComponent({ (short)headers.size() * 10, 2 }, "Table")
{
	_table.push_back(headers);
}

Table::Table(std::vector<std::string>& headers, std::vector<std::vector<std::string>>& data)
	: UIComponent({ (short)headers.size() * 10, (short)(data.size() + 2) }, "Table") // data.size + header
{
	_table.push_back(headers);
	for (auto& i : data)
		_table.push_back(i);
}

Table::Table(short height, std::vector<std::string>& headers, std::vector<std::vector<std::string>>& data)
	: UIComponent({ (short)headers.size() * 10, height }, "Table")
{
	_table.push_back(headers);
	for (auto& i : data)
		_table.push_back(i);
}

Table::Table(short width, short height, std::vector<std::string>& headers, std::vector<std::vector<std::string>>& data)
	: UIComponent({ width, height }, "Table")
{
	_table.push_back(headers);
	for (auto& i : data)
		_table.push_back(i);
}

Table::~Table() {}

void Table::add_row(const std::vector<std::string>& row)
{
	_table.push_back(row);
}

bool Table::is_table(void) const
{
	return true;
}

const std::vector<std::vector<std::string>>& Table::get_table(void) const
{
	return _table;
}

} // namespace ui

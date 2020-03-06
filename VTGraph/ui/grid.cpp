#include "grid.h"

namespace ui {

Grid::Grid(short rows, short cols)
	: UIComponent( {(short)(cols * 2), rows} )
{

}

Grid::~Grid() {}

} // namespace ui

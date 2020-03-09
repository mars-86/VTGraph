#include "euclidean_space.h"

namespace ui {

EuclideanSpace::EuclideanSpace(short width, short height, POSITION position)
	: UIComponent( {width, height}, "EuclideanSpace") {}

EuclideanSpace::EuclideanSpace(EUCLIDEAN_CONTEXT e_context, short width, short height, POSITION position)
	: UIComponent( {width, height}, "EuclideanSpace"), _e_context((e_context == EUCLIDEAN_CONTEXT::_2D) ? "2D" : "3D") {}

EuclideanSpace::~EuclideanSpace() {}

bool EuclideanSpace::is_euclidean_space(void) const
{
	return true;
}

const std::string& EuclideanSpace::get_context(void) const
{
	return _e_context;
}

} // namespace ui

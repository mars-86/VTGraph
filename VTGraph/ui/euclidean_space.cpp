#include "euclidean_space.h"

namespace ui {

EuclideanSpace::EuclideanSpace(short width, short height, POSITION position)
	: UIComponent( {width, height}, "EuclideanSpace") {}

EuclideanSpace::EuclideanSpace(EUCLIDEAN_CONTEXT e_context, short width, short height, POSITION position)
	: UIComponent( {width, height}, "EuclideanSpace"), _e_context(e_context) {}

EuclideanSpace::~EuclideanSpace() {}

bool EuclideanSpace::is_euclidean_space(void) const
{
	return true;
}

} // namespace ui

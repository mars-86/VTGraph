#include "euclidean_space.h"

namespace ui {

EuclideanSpace::EuclideanSpace(short width, short height, POSITION position)
	: UIComponent({ width, height }) {}

EuclideanSpace::EuclideanSpace(EUCLIDEAN_CONTEXT e_context, short width, short height, POSITION position)
	: UIComponent( {width, height} ), _e_context(e_context) {}

EuclideanSpace::~EuclideanSpace() {}


} // namespace ui

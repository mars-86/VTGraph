#include "euclidean_space.h"

namespace ui {
/*
Space2D::Space2D(short width, short height, POSITION position)
	: UIComponent( {width, height}, "EuclideanSpace")
{
    // _layers.push_back(Layer2D(width, height, 0));
    _drawable.reserve(width * height);
    _draw_axis();
}

EuclideanSpace::EuclideanSpace(EUCLIDEAN_CONTEXT e_context, short width, short height, POSITION position)
	: UIComponent( {width, height}, "EuclideanSpace"), _e_context((e_context == EUCLIDEAN_CONTEXT::_2D) ? "2D" : "3D")
{
    // _layers.push_back(Layer2D(width, height, 0));
    _drawable.reserve(width * height);
    _draw_axis();
}

EuclideanSpace::~EuclideanSpace() {}

bool EuclideanSpace::is_euclidean_space(void) const
{
	return true;
}

const std::string& EuclideanSpace::get_context(void) const
{
	return _e_context;
}

void EuclideanSpace::_draw_axis(void)
{
    get_context() == "2D" ? _draw_axis_xy() : _draw_axis_xyz();
}

void EuclideanSpace::_draw_axis_xy(void)
{
    int linear_length = get_width() * get_height() - 1;
    int width = get_width(), height = get_height(), x_offset = width / 2, y_offset = height / 2;
    // for (int i = 0; i < linear_length; i += width)
    //    _layers[0][i + x_offset].set_x(0), _layers[0][y_offset++].set_y(0);
    // for (auto i : _layers[0])
        // _drawable =
}

void EuclideanSpace::_draw_axis_xyz(void)
{

}
*/
} // namespace ui

#ifndef UI_LAYER_H
#define UI_LAYER_H
#pragma once

#include <string>
#include <vector>
#include "graphic.h"

namespace ui {

class Layer {
public:
	Layer(short width, short height, short layer_deep)
        : _width(width), _height(height), _layer_deep(layer_deep)
    {
        // _layer.resize(width * height - 1);
    }

	~Layer() {}

    short get_width(void) const
    {
        return _width;
    }

    void set_width(short width)
    {
        _width = width;
    }

    short get_height(void) const
    {
        return _height;
    }

    void set_height(short height)
    {
        _height = _height;
    }

    short get_deep(void) const
    {
        return _layer_deep;
    }

    void set_deep(short layer_deep)
    {
        _layer_deep = layer_deep;
    }

    int get_linear_size(void) const
    {
        return get_width() * get_height();
    }

private:
    short _width;
    short _height;
    short _layer_deep;
    // ui::Graphic gr(0, 0);
    // std::vector<gr> _layer;
};

}

#endif // !UI_LAYER_H

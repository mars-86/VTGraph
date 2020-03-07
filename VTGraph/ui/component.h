#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H
#pragma once

#include "region.h"

namespace ui {

typedef struct _ComponentSize {
	short rows;
	short cols;
} ComponentSize;

class Component {
public:
	Component() : _size({ 0, 0 }) {}
	Component(const ComponentSize& size) : _size({ size.cols, size.rows }) {}
	virtual ~Component() {}
	virtual void set_size(short width, short height) { _size = {height, width}; }
	virtual const ComponentSize& get_size(void) const { return _size; }
	virtual const short get_width(void) const { return _size.cols; }
	virtual const short get_height(void) const { return _size.rows; }
protected:
	ComponentSize _size;
	Region _region;
};

} // namespace ui

#endif // !UI_COMPONENT_H

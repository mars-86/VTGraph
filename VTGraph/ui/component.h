#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H
#pragma once

namespace ui {

typedef struct _ComponentSize {
	short rows;
	short cols;
} ComponentSize;

class Component {
public:
	Component() : _size( {0, 0} ) {}
	Component(const ComponentSize& size) : _size(size) {}
	virtual ~Component() {}
	virtual void set_size(short width, short height) { _size = {height, width}; }
	virtual const ComponentSize& get_size(void) const { return _size; }
protected:
	ComponentSize _size;
};

} // namespace ui

#endif // !UI_COMPONENT_H

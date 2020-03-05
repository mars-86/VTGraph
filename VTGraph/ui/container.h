#ifndef UI_CONTAINER_H
#define UI_CONTAINER_H
#pragma once

#include <iostream>
#include <map>
#include "component.h"
#include "ui_component.h"
#include "charset.h"

namespace ui {

class Container : public Component {
public:
	Container(const ComponentSize& size);
	virtual ~Container();

	void add(std::string name, UIComponent& uic);
	UIComponent* get_child(std::string child_name) const;

	/* EVENTS */
	// virtual void on_resize(void) = 0;
	// virtual void on_drag(void) = 0;
	// virtual void on_hover(void) = 0;
protected:
	std::map<std::string, UIComponent&> _child;
	Charset _charset;
};

} // namespace ui

#endif // !UI_CONTAINER_H

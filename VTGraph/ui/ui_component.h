#ifndef UI_UI_COMPONENT_H
#define UI_UI_COMPONENT_H
#pragma once

#include <string>
#include "component.h"
// #include "graphic.h"

namespace ui {

enum class POSITION {
	TOP,
	RIGHT,
	BOTTOM,
	LEFT
};

class UIComponent : public Component {
public:
	UIComponent(const ComponentSize& size, std::string type );
	virtual ~UIComponent();

	std::string get_type(void) const;
	/* EVENTS */
	virtual void on_click(void) = 0;
	//virtual void on_hover(void) = 0;
protected:
	std::string _type;
	void _set_type(std::string type);
	// Graphic _drawer;
	std::vector<std::string> _drawable;
};

} // namespace ui

#endif // !UI_UI_COMPONENT_H

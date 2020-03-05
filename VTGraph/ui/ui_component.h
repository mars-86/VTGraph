#ifndef UI_UI_COMPONENT_H
#define UI_UI_COMPONENT_H
#pragma once

#include "component.h"

namespace ui {

enum class POSITION {
	TOP,
	RIGHT,
	BOTTOM,
	LEFT
};

class UIComponent : public Component {
public:
	UIComponent(const ComponentSize& size );
	virtual ~UIComponent();

	/* EVENTS */
	//virtual void on_click(void) = 0;
	//virtual void on_hover(void) = 0;
protected:

};

} // namespace ui

#endif // !UI_UI_COMPONENT_H

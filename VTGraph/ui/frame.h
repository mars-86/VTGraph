#ifndef UI_FRAME_H
#define UI_FRAME_H
#pragma once

#include <map>
#include <string>
#include "container.h"
#include "graphic.h"
#include "ui_component.h"

namespace ui {

using namespace vterm;

class Frame : public Container {
public:
	Frame(short width, short height);
	Frame(std::string app_name, short width, short height);
	~Frame();

	const short get_max_width(void) const;
	const short get_max_height(void) const;
	void set_app_name(std::string app_name);
	const std::string& get_app_name(void) const;
	void visible(void);
private:
	std::string _app_name;
	Graphic* _drawer;
	void _draw(const UIComponent& uic);
};

} // namespace ui

#endif // !UI_FRAME_H

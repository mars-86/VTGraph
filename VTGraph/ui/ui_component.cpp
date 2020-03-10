#include "ui_component.h"

namespace ui {

UIComponent::UIComponent(const ComponentSize& size, std::string type)
	: Component(size), _type(type) {}

UIComponent::~UIComponent() {}

std::string UIComponent::get_type() const
{
	return _type;
}

void UIComponent::_set_type(std::string type)
{
	_type = type;
}

} // namespace ui

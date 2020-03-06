#include "container.h"
#include <iostream>
#include <algorithm>

namespace ui {

Container::Container(const ComponentSize& size)
	: Component(size)
{

}

Container::~Container() {}

void Container::add(std::string name, UIComponent& uic)
{
	_child.push_back( {name, uic} );
}

UIComponent* Container::get_child(std::string child_name) const
{
	std::vector<std::pair<std::string, UIComponent&>>::const_iterator it;
	it = std::find_if(_child.begin(), _child.end(), 
		[&child_name](const std::pair<std::string, UIComponent&>& c) { return c.first == child_name; } );
	if (it == _child.end())
		return nullptr;
	return &(it->second);
}

} // namespace ui


#include "container.h"
#include <iostream>
namespace ui {

Container::Container(const ComponentSize& size)
	: Component(size)
{

}

Container::~Container() {}

void Container::add(std::string name, UIComponent& uic)
{
	_child.insert( {name, uic} );
}

UIComponent* Container::get_child(std::string child_name) const
{
	std::map<std::string, UIComponent&>::const_iterator it;
	it = _child.find(child_name);
	if (it == _child.end())
		return nullptr;
	return &(it->second);	
}

} // namespace ui


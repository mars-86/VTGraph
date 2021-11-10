#ifndef UI_DRAWER_H
#define UI_DRAWER_H
#pragma once

namespace ui {

class Drawer {
public:
	Drawer() {}
	virtual ~Drawer() {}

	virtual void put(char16_t s, int x, int y)
	{
		dwchar_t dwc = { s, x, y };
		// std::cout << dwc;
	}

    void draw(std::string drawable)
    {

    }

protected:
	typedef struct _Symbol {
		char16_t val;
		int x;
		int y;
	} dwchar_t;

private:


};

} // namespace ui

#endif // UI_DRAWER_H

#ifndef TITLE_BAR_H
#define TITLE_BAR_H
#pragma once

#include <string>
#include "bar.h"

namespace ui {

class TitleBar : public Bar {
public:
	TitleBar(std::string title, short width, POSITION position);
	~TitleBar();
	void set_title(const std::string title);
	const std::string get_title() const;
private:
	std::string _title;
};

}

#endif // !TITLE_BAR_H

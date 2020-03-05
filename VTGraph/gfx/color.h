#ifndef GFX_COLOR_H
#define GFX_COLOR_H
#pragma once

#include "rgb.h"

namespace gfx {

class Color {
public:
	Color();
	Color(unsigned char red, unsigned char green, unsigned char blue);
	Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
	~Color();

	void set_rgba(const RGBA& rgba);
	const RGBA& get_rgba(void) const;
	void set_red(const unsigned char red);
	unsigned char get_red(void) const;
	void set_green(const unsigned char green);
	unsigned char get_green(void) const;
	void set_blue(const unsigned char blue);
	unsigned char get_blue(void) const;
	void set_alpha(const unsigned char alpha);
	unsigned char get_alpha(void) const;

	inline int get_color(void)
	{
		return ((_color.r << rgba_r_shift) | (_color.g << rgba_g_shift) | (_color.b << rgba_b_shift)) & rgba_mask;
	}

	inline int get_color_alpha(void)
	{
		return ((_color.r << rgba_r_shift) | (_color.g << rgba_g_shift) | (_color.b << rgba_b_shift) | (_color.a << rgba_a_shift)) & rgba_mask;
	}
private:
	RGBA _color;
};

} // namespace gfx

#endif // GFX_COLOR_H

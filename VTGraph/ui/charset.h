#ifndef CHARSET_H
#define CHARSET_H
#pragma once

namespace ui {

enum class _CHARSET {
	CUPPER_LEFT_CORNER,
	CUPPER_RIGHT_CORNER,
	CBOTTOM_LEFT_CORNER,
	CBOTTOM_RIGHT_CORNER,
	CVERTICAL_BORDER,
	CHORIZONTAL_BORDER
};

class Charset {
public:
	Charset() {}
	~Charset() {}

	// macro avoiding
	const char* _get_symbol(_CHARSET cs) {
		switch (cs) {
		// container charset
		case _CHARSET::CUPPER_LEFT_CORNER:
			return u8"\u2554";
		case _CHARSET::CUPPER_RIGHT_CORNER:
			return  u8"\u2557";
		case _CHARSET::CBOTTOM_LEFT_CORNER:
			return u8"\u255A";
		case _CHARSET::CBOTTOM_RIGHT_CORNER:
			return u8"\u255D";
		case _CHARSET::CVERTICAL_BORDER:
			return u8"\u2551";
		case _CHARSET::CHORIZONTAL_BORDER:
			return u8"\u2550";
		default:
			;
		}
		return "";
	}
};

} // namespace ui

#endif // !CHARSET_H

#ifndef UI_REGION_H
#define UI_REGION_H
#pragma once

#include "../gfx/rect.h"
#include "../gfx/point2d.h"

namespace ui {

template <typename T>
class RegionT {
public:
	RegionT()
		: _limit({ 0, 0, 0, 0 }) {};
	
	RegionT(const gfx::Rect& rect)
	{
		set_limit(rect);
	}

	~RegionT() {}

	typedef struct _RegLimit {
		T left;
		T bottom;
		T right;
		T top;
	} RegLimit;
	
	void set_limit(const gfx::Rect& rect)
	{
		_limit.left = rect.get_origin().get_y();
		_limit.bottom = rect.get_origin().get_x();
		_limit.right = _limit.left + rect.get_width();
		_limit.top = _limit.bottom - rect.get_height();
	}

	const RegLimit& get_limit(void) const
	{
		return _limit;
	}
	
	const gfx::Point2D& get_top_left(void) const
	{
		return { _limit.top, _limit.left };
	}
	
	const gfx::Point2D& get_bottom_left(void) const
	{
		return { _limit.bottom, _limit.left };
	}
	
	const gfx::Point2D& get_top_right(void) const
	{
		return { _limit.top, _limit.right };
	}
	
	const gfx::Point2D& get_bottom_right(void) const
	{
		return { _limit.bottom, _limit.right };
	}
private:
	RegLimit _limit;
};

typedef RegionT<int> Region;
typedef RegionT<double> RegionF;
typedef Region::RegLimit RegLimit;
typedef RegionF::RegLimit RegLimitF;

} // namespace ui

#endif // !UI_REGION_H

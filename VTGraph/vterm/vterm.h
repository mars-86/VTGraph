#ifndef VTERM_VTERM_H
#define VTERM_VTERM_H
#pragma once

#include <cmath>
#include "command.h"
#include "../os/os.h"
#include "../gfx/point2d.h"

#ifdef _WIN32
#define _STDOUT_HANDLE STD_OUTPUT_HANDLE
#else
#define _STDOUT_HANDLE 1
#endif // _WIN32

namespace vterm {

class VTerm : public Command {
public:
	VTerm()
	{
	    set_screen_buffer(VTERM_ALTERNATE_SCREEN_BUFFER);
	    set_cursor_visibility(VTERM_CURSOR_HIDE);
	    _stdh = os::get_std_handle(_STDOUT_HANDLE);
	    os::get_container_size(_stdh, &_cs);
	    std::cout << "R:" << _cs.cs_row << " C:" << _cs.cs_col << std::endl;
	    _buffer.resize(_cs.cs_col * _cs.cs_row, 0);
	    _ratio = floor(_cs.cs_col / _cs.cs_row);
    }

	virtual ~VTerm()
	{
		set_cursor_visibility(VTERM_CURSOR_SHOW);
		set_screen_buffer(VTERM_MAIN_SCREEN_BUFFER);
	}

	virtual void put(const char *s, int x, int y)
	{
		dwchar_t dwc = { (char *)s, x, y };
		std::cout << dwc;
	}

	virtual void put(const char *s, int x, int y, int z)
	{
		dwchar_t dwc = { (char *)s, x, y };
		std::cout << dwc;
	}

	virtual void put_buffer(const std::vector<gfx::Point2D>& points)
	{
	    auto buf = points;
	    /*
	    int y = buf[0].get_y(), remainder = y % _ratio;
        if (remainder) buf[0].set_y(y - remainder);
	    for(int i = 1; i < buf.size(); ++i) {
            y = buf[i].get_y(), remainder = y % _ratio;
            if (remainder) buf[i].set_y(y - remainder);
            // if (buf[i].get_y() - buf[i - 1].get_y() != 0) buf[i].set_y(buf[i].get_y() - (_ratio - 1));
            // std::cout << buf[i].get_y() - buf[i - 1].get_y() << " ";
            if (!(buf[i].get_y() ^ buf[i - 1].get_y()) && !(buf[i].get_x() ^ buf[i - 1].get_x())) buf.erase(buf.begin() + i), --i;
	    }
	    std::cout << buf.size() << std::endl;
	    std::getchar();
	    for(auto i : buf) {
            std::cout << '{' << i.get_x() << " " << i.get_y() << '}' << " ";
	    }
	    std::getchar();*/
        for(auto i : buf) _buffer[_cs.cs_col * (i.get_y() - 1) + i.get_x() - 1] = 1;
	}

	virtual void erase_buffer(const std::vector<gfx::Point2D>& points)
	{
        for(auto i : points) _buffer[_cs.cs_col * (i.get_y() - 1) + i.get_x() - 1] = 0;
	}

	virtual std::vector<int>& get_screen_buffer(void)
	{
        return _buffer;
	}

	virtual std::vector<int>& get_screen_buffer(const std::vector<gfx::Point2D>& points)
	{
	    _points_buffer.clear();
        int y = points[0].get_y();
        int width = 0;
        gfx::Point2D p1 = { points[0].get_x(), points[0].get_y() };
        for (int i = 0; i < points.size(); ++i) {
            while (y == points[i++].get_y()) ++width;
            y = points[i].get_y();

        }
        return _points_buffer;
	}

protected:
	typedef struct _Symbol {
		char* val;
		int x;
		int y;
	} dwchar_t;

	typedef struct _Shape {
        gfx::Point2D point;


    } shape_t;

private:
	friend std::ostream& operator<<(std::ostream& out, const dwchar_t& symbol)
	{
		// std::flush for cursor fluency
		return out << VTERM_ESCAPE << "[" << symbol.y << ";" << symbol.x << "H" << symbol.val << std::flush;
	}
    std::vector<int> _buffer;
    std::vector<int> _points_buffer;
#ifdef _WIN32
    HANDLE _stdh;
#else
    void *_stdh;
#endif // _WIN32
    os::ContainerSize _cs;
    int _ratio;

};

} // namespace vterm

#endif //!VTERM_VTERM_H

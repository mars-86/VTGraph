#include "x11.h"

#ifdef __linux__

#include <stdio.h>
#include <linux/kd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> // for STDOUT_FILENO
#include <poll.h>

#include <X11/Xlib.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>



int _open_default_display(void)
{
	//display = (Display*)malloc(sizeof(Display));
	if (!(display = XOpenDisplay(NULL))) {
		fprintf(stderr, "Cannot open display");
		return -1;
	}
	//return display->display_name;
	return 0;
}

const char* _get_display_name(void)
{
	return display->display_name;
}

void _close_display(void)
{
	XCloseDisplay(display);
	free(display);
}

Display* _get_display(void)
{
	

}

#endif // __linux__

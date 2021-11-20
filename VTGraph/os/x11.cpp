#include "x11.h"

#ifdef __linux__

#ifdef __x11__

#include <stdio.h>
#include <linux/kd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> // for STDOUT_FILENO

#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>

static Display* display;

namespace os {

struct winsize get_window_size(void);

void* _init_instance(ContainerSize* cs)
{
	struct winsize size = get_window_size();
	cs->cs_row = size.ws_row;
	cs->cs_col = size.ws_col;
	printf("%s", "\x1B[1m");
	// TODO - return display ptr
	return NULL;
}

struct winsize get_window_size(void)
{
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return size;
}

int _init_event_handler(void)
{
	if (!(display = XOpenDisplay(NULL))){
		fprintf(stderr, "Cannot open display\n");
		return -1;
	}

	//Window rootw = XDefaultRootWindow(display);

	Window *child_w = NULL;
	unsigned int count_w;
	//Status q_stat = XQueryTree(display, rootw, NULL, NULL, NULL, &count_w);
	int screen;
	Window rootw;
	screen = DefaultScreen (display);
	rootw = RootWindow (display, screen);

	//if (q_stat == 0 )
	//	return 1;

	//XFree(child_w);

	XEvent evt;
	int err = XGrabPointer(
				display,
				rootw,
				False,
				PointerMotionMask | ButtonPressMask,
				GrabModeAsync,
				GrabModeAsync,
				None,
				None,
				CurrentTime
			);
	switch(err) {
		// ...
	}
	while(1) {

	XNextEvent(display, &evt);
    // ...
	printf("Absolute coordinates: %d,%d\n", evt.xbutton.x_root, evt.xbutton.y_root);

	}
    /*struct termios tty_attr;
    int flags;*/

    /* make stdin non-blocking */
    /*flags = fcntl(0, F_GETFL);
    flags |= O_NONBLOCK;
    fcntl(0, F_SETFL, flags);*/

    /* save old keyboard mode */
    /*if (ioctl(0, KDGKBMODE, &old_keyboard_mode) < 0) {
		perror("ioctl");
		return -1;
    }

    tcgetattr(0, &tty_attr_old);*/

    /* turn off buffering, echo and key processing */
    /*tty_attr = tty_attr_old;
    tty_attr.c_lflag &= ~(ICANON | ECHO | ISIG);
    tty_attr.c_iflag &= ~(ISTRIP | INLCR | ICRNL | IGNCR | IXON | IXOFF);
    tcsetattr(0, TCSANOW, &tty_attr);

    if (ioctl(0, KDSKBMODE, K_RAW) < 0){
		perror("ioctl");
		return -1;
	}
	*/
	XCloseDisplay(display);
	return 0;
}

int _get_kb_mode(void)
{
	int kb_mode;
	int fd = open("/dev/input/mouse0", O_RDONLY);
	if (fd < 0 ) {
		perror("ioctl");
		return -1;
    }
	if (ioctl(STDOUT_FILENO, KDGKBMODE, &kb_mode) < 0) {
		perror("ioctl");
		return -1;
    }
    return kb_mode;
}

int _open_default_display(void)
{
	if (!(display = XOpenDisplay(NULL))){
		fprintf(stderr, "Cannot open display\n");
		return -1;
	}
	return 0;
}

Display* _get_display_name(void)
{
	return display;
}

void _close_display(void)
{
	XCloseDisplay(display);
}

} // namespace os

#endif // __x11__

#endif // __linux__

#include "x11.h"

#ifdef __linux__

#include <stdio.h>
#include <linux/kd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> // for STDOUT_FILENO
#include <poll.h>

#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


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

static struct termios tty_attr_old;
static int old_keyboard_mode;

int _init_event_handler(void)
{
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

	return 0;*/
           fd_set rfds;
           struct timeval tv;
           int retval;

	while (1){
		/* Watch stdin (fd 0) to see when it has input. */

        FD_ZERO(&rfds);
        FD_SET(0, &rfds);

        /* Wait up to five seconds. */

        tv.tv_sec = 1;
        tv.tv_usec = 0;
        
		retval = select(1, &rfds, NULL, NULL, &tv);
        /* Don't rely on the value of tv now! */

		if (retval == -1)
			perror("select()");
        else if (retval)
			printf("Data is available now.\n");
        /* FD_ISSET(0, &rfds) will be true. */
        else
			printf("No data within five seconds.\n");
	}
}

} // namespace os

#endif // __linux__

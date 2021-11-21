#include "linux.h"
#include <sys/ioctl.h>
#include <unistd.h>

namespace os {

void *get_std_handle(unsigned long handle)
{
}

void set_console_output_fm(unsigned int format)
{
}

int get_container_size(void *stdh, ContainerSize *cs)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    cs->cs_row = w.ws_row;
    cs->cs_col = w.ws_col;

    return 0;
}

void set_console_font(void *stdh, const wchar_t *name, int width, int height)
{
}

void set_console_mode(void *stdh, unsigned long mode, long *m)
{
}

void *_init_instance(ContainerSize* cs)
{
    get_container_size(nullptr, cs);
}

bool _change_window_message_filter_es(void *handle)
{
}

} // namespace os

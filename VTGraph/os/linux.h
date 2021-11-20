#ifndef OS_LINUX_H
#define OS_LINUX_H

#ifdef __linux__

#include <unistd.h>
#include "platform.h"

namespace os {

void *get_std_handle(unsigned long handle);
void set_console_output_fm(unsigned int format);
int get_container_size(void *stdh, ContainerSize *cs);
void set_console_font(void *stdh, const wchar_t *name, int width, int height);
void set_console_mode(void *stdh, unsigned long mode, long *m);

void *_init_instance(ContainerSize* cs);
bool _change_window_message_filter_es(void *handle);

} // namespace os

#endif // __linux__

#endif // OS_LINUX_H


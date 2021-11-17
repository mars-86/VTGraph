#ifndef OS_X11_H
#define OS_X11_H

#ifdef __linux__

#include <X11/Xlib.h>
#include <unistd.h>
#include "platform.h"

namespace os {

void* _init_instance(ContainerSize* cs);
int _init_event_handler(void);
int _open_default_display(void);
Display* _get_display_name(void);
//const char* _get_display_name(void);
int _get_kb_mode(void);

} // namespace os

#endif // __linux__

#endif // OS_X11_H

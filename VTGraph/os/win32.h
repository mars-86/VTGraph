#ifndef OS_WIN32_H
#define OS_WIN32_H

#ifdef _WIN32

#include <windows.h>
#include "platform.h"

namespace os {

HANDLE get_std_handle(unsigned long handle);
void set_console_output_fm(unsigned int format);
int get_container_size(HANDLE stdh, ContainerSize *cs);
void set_console_font(HANDLE stdh, const wchar_t *name, int width, int height);
void set_console_mode(HANDLE stdh, unsigned long mode, DWORD *m);

HWND _init_instance(ContainerSize* cs);
BOOL _change_window_message_filter_es(HWND handle);

} // namespace os

#endif // _WIN32

#endif // OS_WIN32_H

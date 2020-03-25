#ifndef OS_WIN32_H
#define OS_WIN32_H

#include <windows.h>
#include "platform.h"

namespace os {

HWND _init_instance(ContainerSize* cs);
BOOL _change_window_message_filter_es(HWND handle);

} // namespace os

#endif // OS_WIN32_H

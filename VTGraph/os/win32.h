#ifndef OS_WIN32_H
#define OS_WIN32_H

#include <windows.h>
#include "platform.h"

namespace os {

void* _init_instance(ContainerSize* cs);

} // namespace os

#endif // OS_WIN32_H

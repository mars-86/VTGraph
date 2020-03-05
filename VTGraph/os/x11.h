#ifndef OS_X11_H
#define OS_X11_H

#ifdef __linux__

#include "platform.h"

namespace os {

void* _init_instance(ContainerSize* cs);

} // namespace os

#endif // __linux__

#endif // OS_X11_H

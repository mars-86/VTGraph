#ifndef OS_OS_H
#define OS_OS_H

#ifdef __linux__
#include "x11.h"
#elif _WIN32
#define WINVER 0x0500
#include "win32.h"
#endif // __linux__


#undef NULL
#ifdef __cplusplus
#define NULL nullptr
#else
#define NULL ((void*)0)
#endif // __cplusplus

#endif // OS_OS_H

#ifndef DEBUG_TOOLS_H
#define DEBUG_TOOLS_H
#pragma once

#ifdef __cplusplus
#include "memory_manager.h"
#endif

enum DebugLevel{
	NONE,
	LOW,
	NORMAL,
	HIGH,
	CRITICAL
};

void _DEBUG_PRINTF(int level, const char *fmt, ...);

#endif // !DEBUG_TOOLS_H

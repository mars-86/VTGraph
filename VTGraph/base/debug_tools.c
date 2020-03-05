#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "debug_tools.h"

#ifndef _DEBUG_LVL
#define _DEBUG_LVL NONE
const static int debug_level = _DEBUG_LVL;
#else
const static int debug_level = _DEBUG_LVL;
#endif

void _DEBUG_PRINTF(int level, const char *fmt, ...)
{
	if (level <= debug_level){
		va_list vl;
		va_start(vl, fmt);
		while (*fmt != '\0'){
			if (*fmt == '%'){
				switch(*(++fmt)){
				case 'c':
					printf("%c", va_arg(vl, int));
					break;
				case 'd':
					printf("%d", va_arg(vl, int));
					break;
				case 'f':
					printf("%f", va_arg(vl, double));
					break;
				case 'l':
					printf("%ld", va_arg(vl, long));
					break;
				case 's':
					printf("%s", va_arg(vl, const char*));
					break;
				default:
					;
				}
			}
			++fmt;
		}
		va_end(vl);
	}
}

#ifndef OS_PLATFORM_H
#define OS_PLATFORM_H

#include "types.h"

namespace os {

typedef struct _ContainerSize {
    uint16_t cs_row;
    uint16_t cs_col;
    uint16_t cs_row_max;
    uint16_t cs_col_max;
} ContainerSize;

}

#endif // OS_PLATFORM_H

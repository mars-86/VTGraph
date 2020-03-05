#ifndef MEMOMY_MANAGER_H
#define MEMOMY_MANAGER_H

#include "allocator_block.h"

void* _mem_alloc(std::size_t size, const char* file, int line);
void _mem_dealloc(void* ptr);

#endif // !MEMOMY_MANAGER_H

#ifndef ALLOCATOR_BLOCK_H
#define ALLOCATOR_BLOCK_H

#include <iostream>

void _insert(void* addr, std::size_t size, const char* file, int line);
void _remove(void* addr);
void show_info(void);

#endif // !ALLOCATOR_BLOCK_H

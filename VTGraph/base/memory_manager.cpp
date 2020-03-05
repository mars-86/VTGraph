#include <iostream>
#include <cstdlib>
#include "memory_manager.h"

void* _mem_alloc(std::size_t size, const char* file, int line){
	void *ptr = std::malloc(size);
	_insert(ptr, size, file, line);
#ifdef DEBUG
	std::cout << "Alloc: " << ptr << " " << size << " " << file << " " line << std::endl;
#endif
	return ptr;
}

void _mem_dealloc(void *ptr){
	_remove(ptr);
	std::free(ptr);
#ifdef DEBUG
	std::cout << "Dealloc: " << ptr << std::endl;
#endif
}

void* operator new(std::size_t size, const char* file, int line){
	return _mem_alloc(size, file, line);
}

void* operator new[](std::size_t size, const char* file, int line){
	return _mem_alloc(size, file, line);
}

void* operator new(std::size_t size){
	return _mem_alloc(size, "", 0);
}

void* operator new[](std::size_t size){
	return _mem_alloc(size, "", 0);
}

void operator delete(void *ptr) noexcept{
	_mem_dealloc(ptr);
}

void operator delete[](void *ptr) noexcept{
	_mem_dealloc(ptr);
}

#define new new(__FILE__, __LINE__)

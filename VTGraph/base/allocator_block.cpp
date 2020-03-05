#include <iostream>
#include "allocator_block.h"

struct mem_usage{
	void *addr;
	std::size_t size;
	const char *file;
	int line;
	struct mem_usage* _next;
};

static mem_usage* _alloc = nullptr;

void _insert(void* addr, std::size_t size, const char* file, int line){
	mem_usage* m = (mem_usage*)std::malloc(sizeof(mem_usage));
	if(!m) return;
	m->addr = addr;
	m->size = size;
	m->file = file;
	m->line = line;
	m->_next = nullptr;
	// root
	if(_alloc == nullptr){
		_alloc = m;
	}
	else{
		m->_next = _alloc;
		_alloc = m;
	}
}

void _remove(void* addr){
	mem_usage* p,* q;
	p = q = _alloc;
	if(p){
		// root
		if(addr == p->addr){
			_alloc = p->_next;
			p->_next = nullptr;
		}
		else{
			p = p->_next;
			while( p != nullptr){
				if(addr == p->addr){
					q->_next = p->_next;
					p->_next = nullptr;
					break;
				}
				p = p->_next;
				q = q->_next;
			}
		}
		std::free(p);
	}
}

void show_info(void){
	mem_usage* p;
	std::cout << "Allocated Memory: " << std::endl;
	std::cout << "Address\t\tSize\tFile\t\tLine" << std::endl;
	for(p = _alloc; p != nullptr; p = p->_next)
		std::cout << p->addr << "\t" << p->size << "\t" << p->file << "\t\t" << p->line << std::endl;
}

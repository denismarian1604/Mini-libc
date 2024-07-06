// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	// initialize mem_list only if it hasn't been yet initialized
	if (mem_list_head.prev == NULL)
	{
		mem_list_init();
	}

	// make the mmap syscall
	int prot = PROT_READ | PROT_WRITE;
	int flags = MAP_PRIVATE | MAP_ANONYMOUS;

	void *res = mmap(NULL, size, prot, flags, -1, 0);

	// if the allocation succedded, add the item to the mem_list
	if (res)
		mem_list_add(res, size);

	return res;
}

void *calloc(size_t nmemb, size_t size)
{
	// initialize mem_list only if it hasn't been yet initialized
	if (mem_list_head.prev == NULL)
	{
		mem_list_init();
	}

	// make the mmap syscall
	void *allocated_mem = malloc(nmemb * size);

	// initialize the values with 0
	memset(allocated_mem, 0, nmemb * size);

	// if the allocation succedded, add the item to the mem_list
	if (allocated_mem)
		mem_list_add(allocated_mem, nmemb * size);

	return allocated_mem;
}

void free(void *ptr)
{
	// find the ptr address in the mem_list
	struct mem_list *find_ptr = mem_list_find(ptr);

	// if found
	if (find_ptr)
	{
		// deallocate the memory
		munmap(ptr, find_ptr->len);
		// remove the item from the mem_list
		mem_list_del(ptr);
	}
}

void *realloc(void *ptr, size_t size)
{
	// find the ptr address in the mem_list
	struct mem_list *find_ptr = mem_list_find(ptr);

	// store the old length
	int old_len = find_ptr->len;

	// allocate new memory
	void *new_space = malloc(size);

	// if the allocation succedded, add the item to the mem_list
	if (new_space)
		mem_list_add(new_space, size);

	void *res = memcpy(new_space, ptr, old_len);

	// free ptr
	free(ptr);

	return res;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	// find the ptr address in the mem_list
	struct mem_list *find_ptr = mem_list_find(ptr);

	// store the old length
	int old_len = find_ptr->len;

	// allocate new memory
	void *new_space = malloc(nmemb * size);

	// if the allocation succedded, add the item to the mem_list
	if (new_space)
		mem_list_add(new_space, nmemb * size);

	void *res = memcpy(new_space, ptr, old_len);

	// free ptr
	free(ptr);

	return res;
}

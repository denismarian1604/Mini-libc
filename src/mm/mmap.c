// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	// make the mmap syscall
	long res = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	// check for res less than 0; modify errno
	if (res < 0)
	{
		errno = -res;
		return MAP_FAILED;
	}

	// return res as void *
	return (void *)res;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	// call mremap syscall
	long res = syscall(__NR_mremap, old_address, old_size, new_size, flags);

	// if there was an error, update errno
	if (res < 0)
	{
		errno = -res;
		return MAP_FAILED;
	}

	return (void *)res;
}

int munmap(void *addr, size_t length)
{
	// call munmap syscall
	long res =  syscall(__NR_munmap, addr, length);

	// if there was an error, update errno
	if (res < 0)
	{
		errno = -res;
		return -1;
	}

	return (int)res;
}

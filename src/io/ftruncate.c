// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	// make the ftruncate syscall
	long res = syscall(__NR_ftruncate, (unsigned int)fd, (unsigned long)length);

	// set errno accordingly
	if (res < 0)
	{
		errno = -res;
		return -1;
	}

	// succes
	return (int)res;
}

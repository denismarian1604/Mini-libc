// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	// make the close syscall
	long res = syscall(3, (unsigned int)fd);

	if (res < 0)
	{
		errno = -res;
		return -1;
	}

	return (int)res;
}

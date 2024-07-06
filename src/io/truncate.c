// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <sys/types.h>

int truncate(const char *path, off_t length)
{
	// make the truncate syscall
	long res = syscall(__NR_truncate, path, length);

	// check, similarly to open.c, the returned value
	if (res < 0)
	{
		errno = -res;
		return -1;
	}

	return 0;
}

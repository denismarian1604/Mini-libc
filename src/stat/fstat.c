// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	// make the fstat syscall
	int res = syscall(__NR_fstat, (unsigned int)fd, st);

	if (res < 0)
	{
		// set errno accordingly to the return value
		errno = -res;
		// return -1 as the call failed
		return -1;
	}

	return 0;
}

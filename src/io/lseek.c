// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	// make the lseek syscall
	off_t res = syscall(__NR_lseek, (unsigned int)fd, offset, (unsigned int)whence);

	// check for errors; if so, modify errno
	if (res < 0)
	{
		errno = -res;
		return -1;
	}

	// return result
	return res;
}

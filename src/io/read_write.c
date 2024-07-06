// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>

ssize_t write(int fd, const void *buf, size_t len)
{
	// make the write syscall
	ssize_t res = syscall(__NR_write, fd, buf, len);

	// if there was an error, update errno
	if (res < 0)
	{
		errno = -res;
		return -1;
	}

	return res;
}

ssize_t read(int fd, void *buf, size_t len)
{
	// make the read syscall
	ssize_t res =  syscall(__NR_read, fd, buf, len);

	// if there was an error, update errno
	if (res < 0)
	{
		errno = -res;
		return -1;
	}

	return res;
}

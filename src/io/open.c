// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
    // suppose we have no mode given
    int mode = 0;

    // the create flag is available; check for mode
    if (flags & O_CREAT)
    {
        // start new variabile list
         va_list modes;
         va_start(modes, flags);

        // get first value after flags
         mode = va_arg(modes, int);
         va_end(modes);
    }

    // make the open syscall
    long res = syscall(__NR_open, filename, flags, mode);

    // if there was an error, update errno
    if (res < 0)
    {
        errno = -res;
        return -1;
    }

    return (int)res;
}

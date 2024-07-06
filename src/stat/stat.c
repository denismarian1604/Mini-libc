// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf) {
    // make the stat syscall
    int res = syscall(__NR_stat, path, buf);

    if (res < 0) {
		// set errno accordingly to the return value
        errno = -res;
		// return -1 as the call failed
        return -1;
    }

    return 0;
}

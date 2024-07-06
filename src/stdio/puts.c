#include <stdio.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int putchar(int c)
{
    // make the write syscall
    long res = syscall(__NR_write, 1, (const char *)&c, 1);

    // if there was an error, update errno
	if (res < 0)
	{
		errno = -res;
		return -1;
	}

	return (int)res;
}

int puts(const char *str)
{
    // if the string is empty, return error
    if (str == NULL)
        return -1;

    // while the current character is not \0, keep going
    while (*str)
    {
        putchar(*str);
        str++;
    }

    // print a newline
    putchar('\n');

    return 1;
}

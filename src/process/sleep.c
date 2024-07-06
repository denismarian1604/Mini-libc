#include <unistd.h>
#include <internal/syscall.h>
#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
{
    // return the syscall for nanosleep
    long res = syscall(__NR_nanosleep, rqtp, rmtp);

    // if there was an error, update errno
	if (res < 0)
	{
		errno = -res;
		return -1;
	}

	return (int)res;
}

unsigned int sleep(unsigned int seconds)
{
    // declare required and remaining time
    struct timespec rqtp, rmtp;

    rqtp.tv_sec = seconds;
    rqtp.tv_nsec = 0;

    rmtp.tv_sec = rmtp.tv_nsec = 0;

    // call nanosleep function
    return nanosleep(&rqtp, &rmtp);
}

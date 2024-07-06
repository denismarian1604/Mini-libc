/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef	__TIME_H__
#define	__TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

// declare time_t data type
typedef long int time_t;

// declare the timespec struct
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

// define the two required functions
unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);

#ifdef __cplusplus
}
#endif

#endif

// rand.h
//
// macros for random numbers!

#include <stdlib.h>
#include <math.h>

#define rand_float() (float)rand()/(float)RAND_MAX
#define rand_int(max) (int)floor((float)max * rand_float())
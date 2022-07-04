// annealing.h
//
// header file for annealing functions

#include <stdlib.h>
#include <math.h>
#include "rand.h"
#include "tour.h"

void sample_cycle(tour tr, int *cycle, float temp);
// annealing.h
//
// header file for annealing functions

#include <stdlib.h>
#include <math.h>
#include "rand.h"
#include "tour.h"

typedef struct {
    int cycles; // number of cycles
    int steps; // steps per cycle
    float *temps;
} annealing_schedule;

void sample_cycle(tour tr, int *cycle, float temp);
float linear_temp(float temp, float alpha);
float geometric_temp(float temp, float alpha);
float slow_decrease_temp(float temp, float alpha);
annealing_schedule create_schedule(int cycles, int steps, 
    float (*temp_func)(float, float), float initial_temp, float alpha);
// tour.h
//
// header for functions/data structures related to
// the salesman's tour.

#include <math.h>
#include "rand.h"

typedef struct {
    float x;
    float y;
} point;

typedef struct {
    int num_cities;
    point *points;
} tour;

point random_point(float x_max, float y_max);
float distance(point pt1, point pt2);
tour make_tour(int num_cities, float x_max, float y_max);
int *random_cycle(tour tr);
void swap_two(tour tr, int *cycle);
void copy_cycle(tour tr, int *cycle1, int *cycle2);
float tour_distance(tour tr, int *cycle);
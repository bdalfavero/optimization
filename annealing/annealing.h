// annealing.h
//
// header file for annealing functions

#include<stdlib.h>
#include<math.h>

#define rand_float() (float)rand()/(float)RAND_MAX
#define rand_int(max) (int)floor((float)max * rand_float())
// define macro for distance between two cities
// i is from index between 0 and num_cities,
// j is to index.
// n.b. a pointer must be passed as prob!
#define distance(prob, i, j) (prob->distance_array)[prob->num_cities * i + j]

// define a type for the length of each tour
// each city is assigned an index in range [0, N-1]
// we can make a symmetric distance matrix to sum this up.
// the distance between two cities is a float with a max value.
typedef struct{
    int num_cities;
    float max_distance;
    float *distance_array; // the matrix values stored as a flat array.
} sales_problem;

sales_problem *make_random_instance(int num_cities, float max_dist);
int *hamiltonian_cycle(int max);
float cycle_distance(sales_problem *prob, int *cycle);
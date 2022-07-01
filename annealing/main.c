// main.c
//
// main file for simulated annealing program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "annealing.h"

int main() {

    sales_problem *prob;
    int* cycle;

    srand((int)clock());

    prob = make_random_instance(4, 10.0);
    cycle = hamiltonian_cycle(prob->num_cities);

    for (int i = 0; i < prob->num_cities; i++) {
        for (int j = 0; j < prob->num_cities; j++) {
            printf("%f ", (prob->distance_array)[prob->num_cities * i + j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < prob->num_cities; i++) {
        printf("%d ", cycle[i]);
    }
    printf("\n");

    // evaluate the distance of a given cycle
    printf("\ndistance: %f\n", cycle_distance(prob, cycle));

    free(prob);
    free(cycle);

    return 0;
}
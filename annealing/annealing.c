// annealing.c
//
// functions used for simulated annealing.

#include<stdlib.h>
#include"annealing.h"

sales_problem *make_random_instance(int num_cities, float max_dist) {
    // make a random instance of the travelling salesman problem.

    sales_problem *prob;
    float rn;
    
    prob = malloc(sizeof(sales_problem));
    prob->num_cities = num_cities;
    prob->max_distance = max_dist;
    prob->distance_array = malloc(num_cities * num_cities * sizeof(float));

    // we must fill in a symmetric matrix. thus, iterate over every row
    // and only iterate over column values less than it. assign both elements 
    // in one iteration.
    for (int i_row = 0; i_row <= (num_cities - 1); i_row++) {
        for (int j_col = 0; j_col <= i_row; j_col++) {
            if (i_row != j_col) {
                rn = prob->max_distance * rand_float();
                (prob->distance_array)[num_cities * i_row + j_col] = rn;
                (prob->distance_array)[num_cities * j_col + i_row] = rn;
            } else {
                (prob->distance_array)[num_cities * i_row + j_col] = 0.;
            }

            
        }
    }

    return prob;
}

int *hamiltonian_cycle(int max) {
    // make a hamiltonian cycle from 0 to max.

    int randi;
    int *used, *cycle;

    // generate a hamiltonian cycle over the city indices.
    // use int values 0 and 1 as bools.
    used = malloc(max * sizeof(int));
    cycle = malloc(max * sizeof(int));
    for (int i = 0; i < max; i++) {
        // set the flags to all unused
        used[i] = 0;
    }
    for (int i = 0; i < max; i++) {
        // fill in each element of the cycle
        while (1) {
            // generate a random int for next element
            randi = rand_int(max);
            // if it is unused, set it to used and break.
            if (!used[randi]) {
                used[randi] = 1;
                break;
            }
        }
        cycle[i] = randi;
    }

    free(used);

    return cycle;
}

float cycle_distance(sales_problem *prob, int *cycle) {
    // return the distance of a cycle.

    float dist = 0.;

    for (int i = 1; i <= prob->num_cities; i++) {
        dist += distance(prob, cycle[i - 1], cycle[i]);
    }

    return dist;
}
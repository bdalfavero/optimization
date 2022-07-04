// annealing.c
//
// functions used for simulated annealing.

#include <stdlib.h>
#include "rand.h"
#include "annealing.h"

void sample_cycle(tour tr, int *cycle, float temp) {
    // sample the next cycle given current cycle
    // with known temperature
    // this function modifies the cycle in-place.

    int *new_cycle;
    float d1, d2, r, p_accept;

    // evaluate the difference in cost function
    // for the current state and one of its neighbors.
    // copy the current cycle into a new location in memory,
    // then swap two of its values.
    new_cycle = malloc(tr.num_cities * sizeof(int));
    copy_cycle(tr, cycle, new_cycle);
    swap_two(tr, new_cycle);
    d1 = tour_distance(tr, cycle);
    d2 = tour_distance(tr, new_cycle);

    // either accept or reject the new state
    if (d2 < d1) {
        // accept the solution!
        copy_cycle(tr, new_cycle, cycle);
    } else {
        // if we draw a number below the acceptance probability,
        // modify the state.
        r = rand_float();
        p_accept = exp(-(d2 - d1) / temp);
        if (r < p_accept) {
            copy_cycle(tr, new_cycle, cycle);
        }
    }

    free(new_cycle);
}
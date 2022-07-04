// main.c
//
// main file for simulated annealing program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "annealing.h"

int main() {

    tour tr;
    int *cycle, *old_cycle;
    int state_changed;

    srand((int)clock());

    tr = make_tour(10, 1.0, 1.0);
    cycle = random_cycle(tr);
    old_cycle = malloc(tr.num_cities * sizeof(int));
    
    for (int i = 0; i < tr.num_cities; i++) {
        printf("%d ", cycle[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        // make a copy of the current state for comparison
        copy_cycle(tr, cycle, old_cycle);
        // sample a new state and print
        sample_cycle(tr, cycle, 10.);
        for (int i = 0; i < tr.num_cities; i++) {
            printf("%d ", cycle[i]);
        }
        // if the state did not change, print 'f'
        // otherwise, print 't'
        state_changed = 0;
        for (int i = 0; i < tr.num_cities; i++) {
            if (old_cycle[i] != cycle[i]) {
                state_changed = 1;
                break;
            }
        }
        if (state_changed == 1) {
            printf(" t");
        } else {
            printf(" f");
        }
        printf("\n");
    }

    free(cycle);
    free(old_cycle);
    
    return 0;
}
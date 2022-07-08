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

    print_cycle(tr, cycle);
    
    for (int i = 0; i < 10; i++) {
        // sample a new state and print
        sample_cycle(tr, cycle, 10.);
        print_cycle(tr, cycle);
    }

    free(cycle);
    
    return 0;
}
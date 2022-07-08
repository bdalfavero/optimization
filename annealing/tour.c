// tour.c
//
// functions related to the tour

#include <stdio.h>
#include "tour.h"

point random_point(float x_max, float y_max) {
    // return a random point within the bounds.

    point pt;

    pt.x = x_max * rand_float();
    pt.y = y_max * rand_float();

    return pt;
}

float distance(point pt1, point pt2) {
    // Euclidian distance between two points in the plane

    float dist;

    dist = sqrt(pow((pt1.x - pt2.x), 2) + pow((pt1.y - pt2.y), 2));

    return dist;
}

tour make_tour(int num_cities, float x_max, float y_max) {
    // make a tour of a nubmer of cities in a plane with given
    // boundaries

    tour tr;

    tr.num_cities = num_cities;
    tr.points = malloc(num_cities * sizeof(point));
    for (int i = 0; i < num_cities; i++) {
        tr.points[i] = random_point(x_max, y_max);
    }

    return tr;
}

int *random_cycle(tour tr) {
    // generate a hamiltonian cycle for a tour.

    int *cycle = malloc(tr.num_cities * sizeof(int));
    // used will used 0, 1 as bools to say if a city already exits in the cycle.
    int *used = malloc(tr.num_cities * sizeof(int)); 
    int cur_i;

    // initialize the arrays to zero
    for (int i = 0; i < tr.num_cities; i++) {
        used[i] = 0;
        cycle[i] = 0;
    }

    // fill in the array of cities.
    for (int i = 0; i < tr.num_cities; i++) {
        // find a thus-unused city
        cur_i = rand_int(tr.num_cities);
        while (1) {
            if (!used[cur_i]) {
                used[cur_i] = 1;
                break;
            }
            cur_i = rand_int(tr.num_cities);
        }
        cycle[i] = cur_i;
    }

    free(used);
    return(cycle);
}

void swap_two(tour tr, int *cycle) {
    // swap two indices in a cycle
    // these will be used as nearest neighbors in the annealing.

    int idx1, idx2, temp;

    idx1 = rand_int(tr.num_cities);
    idx2 = rand_int(tr.num_cities);
    while (1) {
        if (idx2 != idx1) {
            break;
        } else {
            idx2 = rand_int(tr.num_cities);
        }
    }
    temp = cycle[idx1];
    cycle[idx1] = cycle[idx2];
    cycle[idx2] = temp;

    return;
}

void copy_cycle(tour tr, int *cycle1, int *cycle2) {
    // copy a the contents of cycle1 into cycle2
    // this overwites cycle2!

    for (int i = 0; i < tr.num_cities; i++) {
        cycle2[i] = cycle1[i];
    }
}

void print_cycle(tour tr, int *cycle) {
    // print a cycle to stdout.

    for (int i = 0; i < tr.num_cities; i++) {
        printf("%d ", cycle[i]);
    }
    printf("\n");
}

float tour_distance(tour tr, int *cycle) {
    // return the distace of a full tour!

    float dist;

    for (int i = 1; i < tr.num_cities; i++) {
        dist += distance(tr.points[cycle[i]], tr.points[cycle[i-1]]);
    }

    return dist;
}
#include <stdio.h>
#include <stdlib.h> // for atoi
#include "MemoryManager.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Guard may not be necessary? Spec says we can assume correct # of input args...
        fprintf(stderr, "Usage: %s <seed>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    srand(seed);

    printf("[Driver] With seed: %d\n", seed);

    float running_ratio = get_running_ratio();

    printf("[Driver] AVG perfect_sqr/non_perfect_sr ratio: %.6f\n", running_ratio);

    return 0;
}

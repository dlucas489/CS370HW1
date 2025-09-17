#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MemoryManager.h"

// internal state.
static int memory_allocations = 0;

// helpers
int* safe_malloc(int size) { //safe memory allocation
    // size = number of ints to allocate.
    if (size <= 0) {
        // treat nonpositive as fatal errs
        printf("[MemoryManager] ERROR: Invalid allocation size %d\n", size);
        exit(EXIT_FAILURE);
    }
    int *ptr = (int*)malloc(sizeof(int) * (size_t)size);
    if (ptr == NULL) {
        printf("[MemoryManager] ERROR: Out of memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int* tracked_malloc(int size) {
    int *p = safe_malloc(size);
    memory_allocations++;
    return p;
}

void tracked_free(void *ptr, int size) {
    (void)size; // unecessary
    if (ptr != NULL) {
        free(ptr);
        memory_allocations--;
    }
}

// print like example i/o's
void print_memory_summary(void) {
    if (memory_allocations == 0) {
        printf("[MemoryManager] Final summary - 0 memory blocks still allocated\n");
        printf("[MemoryManager] All memory successfully freed\n");
    } else {
        printf("[MemoryManager] WARNING: Potential memory leak detected!\n");
    }
}

// Spec helpers
int random_in_range(int lower_bound, int upper_bound) {
    // lower inclusive, upper exclusive
    // lower must be less than upper as a precondition
    int span = upper_bound - lower_bound;
    if (span <= 0) {
        // guard
        return lower_bound;
    }
    return (rand() % span) + lower_bound;
}

static int is_perfect_square(int x) {
    if (x < 0) return 0;
    int r = (int)(sqrt((double)x) + 0.5); // roudning
    return r * r == x;
}

int get_square_count(int *array, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (is_perfect_square(array[i])) {
            count++;
        }
    }
    return count;
}

// Core entry. called by driver.c

float get_running_ratio(void) {
    //Ascertain num of iterations
    int totalIterations = random_in_range(50, 100);
    printf("[MemoryManager] Number of iterations is: %d\n", totalIterations);

    // track max ratio
    double max_ratio = -1.0;
    int max_iter = -1;

    // running average. ratios / iterations
    double sum_ratios = 0.0;

    for (int iter = 1; iter <= totalIterations; iter++) {

        // Random arr.size [50,100]
        int arraySize = random_in_range(50, 200);

        // Allocation
        int *arr = tracked_malloc(arraySize);

        for (int i = 0; i < arraySize; i++) {
            arr[i] = random_in_range(50, 200);
        }

        // Perfect square counter
        int squares = get_square_count(arr, arraySize);
        int non_squares = arraySize - squares;

        // 6) Compute ratio (zero division guard to be safe)
        double ratio = (non_squares == 0) ? 0.0 : ((double)squares / (double)non_squares);

        sum_ratios += ratio;

        // max ratio and iteration tracker
        if (ratio > max_ratio) {
            max_ratio = ratio;
            max_iter = iter;
        }

        // deallocation
        tracked_free(arr, arraySize);
    }

    // after loop. report iteration + max ration
    printf("[MemoryManager] Iteration with MAX perfect_sqr/non_perfect_sqr ratio: %d\n", max_iter);

    print_memory_summary();

    float avg = (float)(sum_ratios / (double)totalIterations);
    return avg;
}

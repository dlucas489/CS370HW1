#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

// called by driver
float get_running_ratio(void);

// Helpers
int   random_in_range(int lower_bound, int upper_bound);
int   get_square_count(int *array, int size);

// Memory safety & tracking
int*  safe_malloc(int size);
int*  tracked_malloc(int size);
void  tracked_free(void *ptr, int size); 
void  print_memory_summary(void);

#ifdef __cplusplus
}
#endif

#endif

//
// Created by root on 11/24/19.
//

#include <stdlib.h>

#ifndef QUICKSORT_RADIX_SORT_COMPARISON_UTILS_H
#define QUICKSORT_RADIX_SORT_COMPARISON_UTILS_H

void print_arr(int *arr, size_t start, size_t end);
int * gen_random_arr(size_t size, int lowest_val, int highest_val);
int int_compare_func(const void *, const void *);

#endif //QUICKSORT_RADIX_SORT_COMPARISON_UTILS_H

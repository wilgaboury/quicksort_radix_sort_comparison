//
// Created by root on 11/26/19.
//

#include <stdlib.h>

#include "types.h"

#ifndef QUICKSORT_RADIX_SORT_COMPARISON_PIVOT_SELECTION_H
#define QUICKSORT_RADIX_SORT_COMPARISON_PIVOT_SELECTION_H

size_t median_quickselect_helper(int *arr, size_t *indices, size_t start, size_t end, size_t middle, pivot_selector_func_t pivot_selector);
size_t median_quickselect(int *arr, size_t len, pivot_selector_func_t pivot_selector);
size_t pivot_end(int *arr, size_t start, size_t end);
size_t pivot_median_3_split(int *arr, size_t start, size_t end);
size_t pivot_median_5_split(int *arr, size_t start, size_t end);
size_t pivot_median_random(int *arr, size_t start, size_t end, size_t num_to_check);

#endif //QUICKSORT_RADIX_SORT_COMPARISON_PIVOT_SELECTION_H

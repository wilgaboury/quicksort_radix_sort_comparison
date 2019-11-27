//
// Created by root on 11/24/19.
//

#include <stdlib.h>

#include "types.h"

#ifndef QUICKSORT_RADIX_SORT_COMPARISON_TESTER_H
#define QUICKSORT_RADIX_SORT_COMPARISON_TESTER_H

void validate_sorted(int *arr, size_t len);
void validate_quicksort(void (*sort)(int *, size_t, size_t, pivot_selector_func_t), size_t test_size, pivot_selector_func_t pivot_selector);
void validate_median(median_finder_func_t median_finder, size_t test_size, pivot_ind_selector_func_t pivot_selector);

#endif //QUICKSORT_RADIX_SORT_COMPARISON_TESTER_H

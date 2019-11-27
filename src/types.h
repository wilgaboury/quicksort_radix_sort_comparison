//
// Created by root on 11/25/19.
//

#include <stdlib.h>

#ifndef QUICKSORT_RADIX_SORT_COMPARISON_TYPES_H
#define QUICKSORT_RADIX_SORT_COMPARISON_TYPES_H

typedef size_t (*pivot_selector_func_t)(int*, size_t, size_t);
typedef size_t (*pivot_ind_selector_func_t)(int*, size_t*, size_t, size_t);
typedef size_t (*median_finder_func_t)(int*, size_t, pivot_ind_selector_func_t);

#endif //QUICKSORT_RADIX_SORT_COMPARISON_TYPES_H

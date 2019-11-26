//
// Created by root on 11/24/19.
//

#include <stdlib.h>

#include "types.h"

#ifndef QUICKSORT_RADIX_SORT_COMPARISON_QUICKSORTS_H
#define QUICKSORT_RADIX_SORT_COMPARISON_QUICKSORTS_H

void quicksort_stdlib (int *arr, size_t start, size_t end, pivot_selector_func_t pivot_selector);
void quicksort_standard (int *arr, size_t start, size_t end, pivot_selector_func_t pivot_selector);
void quicksort_out_in (int *arr, size_t start, size_t end, pivot_selector_func_t pivot_selector);


#endif //QUICKSORT_RADIX_SORT_COMPARISON_QUICKSORTS_H

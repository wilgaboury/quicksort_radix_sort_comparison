//
// Created by root on 11/24/19.
//

#include <stdlib.h>

#ifndef QUICKSORT_RADIX_SORT_COMPARISON_QUICKSORTS_H
#define QUICKSORT_RADIX_SORT_COMPARISON_QUICKSORTS_H

void quicksort_standard (int *arr, size_t start, size_t end, size_t (*pivot_selector)(int*, size_t, size_t));
void quicksort_out_in (int *arr, size_t start, size_t end, size_t (*pivot_selector)(int*, size_t, size_t));


#endif //QUICKSORT_RADIX_SORT_COMPARISON_QUICKSORTS_H

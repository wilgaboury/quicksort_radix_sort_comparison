//
// Created by root on 11/26/19.
//

#include "types.h"
#include <math.h>

#ifndef QUICKSORT_RADIX_SORT_COMPARISON_PIVOT_SELECTION_H
#define QUICKSORT_RADIX_SORT_COMPARISON_PIVOT_SELECTION_H

size_t median_quickselect_standard_helper(int *arr, size_t *indices, size_t start, size_t end, size_t middle, pivot_ind_selector_func_t pivot_selector);
size_t median_quickselect_standard(int *arr, size_t len, pivot_ind_selector_func_t pivot_selector);

size_t pivot_end(int *arr, size_t start, size_t end);
size_t pivot_end_ind(int *arr, size_t *indices, size_t start, size_t end);

size_t pivot_median_k_split(int *arr, size_t k, size_t start, size_t end, pivot_ind_selector_func_t pivot_selector);
size_t pivot_median_k_split_ind(int *arr, size_t *indices, size_t k, size_t start, size_t end, pivot_ind_selector_func_t pivot_selector);
size_t pivot_median_3_split(int *arr, size_t start, size_t end);
size_t pivot_median_3_split_ind(int *arr, size_t *indices, size_t start, size_t end);
size_t pivot_median_5_split(int *arr, size_t start, size_t end);
size_t pivot_median_5_split_ind(int *arr, size_t *indices, size_t start, size_t end);
size_t pivot_median_crn_split(int *arr, size_t start, size_t end);
size_t pivot_median_crn_split_ind(int *arr, size_t *indices, size_t start, size_t end);

size_t pivot_median_k_random(int *arr, size_t k, size_t start, size_t end, pivot_ind_selector_func_t pivot_selector);
size_t pivot_median_k_random_ind(int *arr, size_t *indices, size_t k, size_t start, size_t end, pivot_ind_selector_func_t pivot_selector);
size_t pivot_median_3_random(int *arr, size_t start, size_t end);
size_t pivot_median_3_random_ind(int *arr, size_t *indices, size_t start, size_t end);
size_t pivot_median_5_random(int *arr, size_t start, size_t end);
size_t pivot_median_5_random_ind(int *arr, size_t *indices, size_t start, size_t end);
size_t pivot_median_crn_random(int *arr, size_t start, size_t end);
size_t pivot_median_crn_random_ind(int *arr, size_t *indices, size_t start, size_t end);


#endif //QUICKSORT_RADIX_SORT_COMPARISON_PIVOT_SELECTION_H

//
// Created by Calvin Hirsch on 10/29/2019.
//

#include "tester.h"
#include "types.h"
#include <stdio.h>
#include "utils.h"
#include "quicksorts.h"

void validate_sorted(int *arr, size_t len) {
    size_t fails = 0;
    for (int i = 1; i < len; i++) {
        if (arr[i] < arr[i - 1]) {
            fails++;
        }
    }
    if (fails) { printf("SORT VALIDATION FAILED: %d fails\n", fails); }
    else { printf("SORT VALIDATION SUCCEEDED\n"); }
}

void validate_quicksort(void (*sort)(int *, size_t, size_t, pivot_selector_func_t), size_t test_size, pivot_selector_func_t pivot_selector) {
    int *arr = gen_random_arr(test_size, 0, 10000);
    (*sort)(arr, 0, test_size - 1, pivot_selector);
    validate_sorted(arr, test_size);
    free(arr);
}

void validate_median(median_finder_func_t median_finder, size_t test_size, pivot_ind_selector_func_t pivot_selector) {
    test_size += (test_size % 2 ? 0 : 1);
    int *arr = gen_random_arr(test_size, 0, 50);

    //print_arr(arr, 0, test_size - 1);

    int median_est = arr[(*median_finder)(arr, test_size, pivot_selector)];
    qsort(arr, test_size, sizeof(int), &int_compare_func);
    //printf("Sorted: ");
    //print_arr(arr, 0, test_size - 1);

    int median_ind = test_size / 2;
    int median = arr[median_ind];

    int median_est_ind = -1;
    for (size_t i = 0; i < test_size; i++) {
        if (arr[i] == median_est) { median_est_ind = i; }
    }

    if (median == median_est) {
        printf("MEDIAN VALIDATION SUCCEEDED\n");
    }
    else {
        printf("MEDIAN VALIDATION FAILED -- Received: %d (%d), Actual: %d (%d)\n", median_est, median_est_ind, median, median_ind);
    }

    free(arr);
}
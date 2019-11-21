//
// Created by Calvin Hirsch on 10/29/2019.
//

#include <stdlib.h>

int compare_func (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int *gen_random_arr(size_t size, int lowest_val, int val_range) {
    int *arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % val_range + lowest_val;
    }

    return arr;
}

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

void validate_quicksort(void (*sort)(int *, size_t, size_t, size_t (*pivot_selector)(int*, size_t, size_t)), size_t test_size, size_t (*pivot_selector)(int*, size_t, size_t)) {
    int *arr = gen_random_arr(test_size, 0, 100000);
    (*sort)(arr, 0, test_size - 1, pivot_selector);

    validate_sorted(arr, test_size);
}

void validate_median(size_t (*median_finder)(int*, size_t, size_t (*pivot_selector)(int*, size_t, size_t)), size_t test_size, size_t (*pivot_selector)(int*, size_t, size_t)) {
    test_size += (test_size % 2 ? 0 : 1);
    int *arr = gen_random_arr(test_size, 0, 100000);

    int median = arr[(*median_finder)(arr, test_size, pivot_selector)];
    qsort(arr, test_size, sizeof(int), compare_func);

    if (arr[test_size / 2] == median) {
        printf("MEDIAN VALIDATION SUCCESSFUL\n");
    }
    else {
        printf("MEDIAN VALIDATION FAILED: Received %d but expected %d", median, arr[test_size / 2]);
    }
}
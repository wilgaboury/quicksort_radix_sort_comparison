//
// Created by root on 11/24/19.
//

#include "utils.h"
#include <stdio.h>

void print_arr(int *arr, size_t start, size_t end) {
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_arr_indices(int *arr, size_t* indices, size_t start, size_t end) {
    for (size_t i = start; i <= end; i++) {
        printf("%d ", arr[indices[i]]);
    }
    printf("\n");
}

int *gen_random_arr(size_t size, int lowest_val, int val_range) {
    int *arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % val_range + lowest_val;
    }

    return arr;
}

int int_compare_func (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}
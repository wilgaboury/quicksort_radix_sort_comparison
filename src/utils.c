//
// Created by root on 11/24/19.
//

#include <stdio.h>

void print_arr(int *arr, size_t start, size_t end) {
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int * gen_random_arr(size_t size, int lowest_val, int val_range) {
    int *arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % val_range + lowest_val;
    }

    return arr;
}
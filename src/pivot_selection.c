//
// Created by Calvin Hirsch on 11/20/2019.
//

#include "pivot_selection.h"
#include "utils.h"
#include <stdio.h>

// MEDIAN FINDING METHODS (return index of median)

// Quickselect method using indices array to keep track of changing value locations and return index without modifying original array
size_t median_quickselect_standard_helper(int *arr, size_t *indices, size_t start, size_t end, size_t middle, pivot_ind_selector_func_t pivot_selector) {
    //printf("---------\n%d -> %d\n", start, end);
    size_t start_large, start_unvisited, pivot_ind, temp, pivot;

    if (start + 1 < end) {
        start_large = start;
        start_unvisited = start;
        pivot_ind = pivot_selector(arr, indices, start, end);
        //printf("P: %d\n", pivot_ind);
        pivot = arr[indices[pivot_ind]];

        temp = indices[pivot_ind];
        indices[pivot_ind] = indices[end];
        indices[end] = temp;
        pivot_ind = end;

        while (start_unvisited < pivot_ind) {
            // If current item is less than pivot, swap it with the first element of the large array
            if (arr[indices[start_unvisited]] < pivot) {
                temp = indices[start_large];
                indices[start_large] = indices[start_unvisited];
                indices[start_unvisited] = temp;
                start_large++;
            }

            start_unvisited++;
            //printf(" > %d", start_large);
        }
        //printf("\n");

        temp = indices[pivot_ind];
        indices[pivot_ind] = indices[start_large];
        indices[start_large] = temp;

        //printf("Array: ");
        //print_arr_indices(arr, indices, start, end);
        //printf("Pivot: %d (%d)\n", arr[indices[start_large]], start_large);

        // start_large is now the pivot location
        if (start_large < middle) {
            return median_quickselect_standard_helper(arr, indices, start_large + 1, end, middle, pivot_selector);
        }
        else if (start_large > middle) {
            return median_quickselect_standard_helper(arr, indices, start, start_large - 1, middle, pivot_selector);
        }
        return indices[start_large];
    }
    else if (start < end) {
        if (arr[indices[start]] > arr[indices[end]]) {
            size_t temp = indices[start];
            indices[start] = indices[end];
            indices[end] = temp;
        }
        
        if (start == middle) { return indices[start]; }
        else { return indices[end]; }
    }
    return indices[start];
}

// Quickselect based on standard quicksort
size_t median_quickselect_standard(int *arr, size_t len, pivot_ind_selector_func_t pivot_selector) {
    size_t indices[len];
    for (size_t i = 0; i < len; i++) { indices[i] = i; }

    return median_quickselect_standard_helper(arr, indices, 0, len - 1, len / 2, pivot_selector);
}


// PIVOT SELECTION METHODS (return index of pivot)

// Pivot on last element
size_t pivot_end(int *arr, size_t start, size_t end) {
    return end;
}

// Pivot on last element (operates on index array)
size_t pivot_end_ind(int *arr, size_t *indices, size_t start, size_t end) {
    return end;
}

// General function for median of k values with evenly split indices
size_t pivot_median_k_split(int *arr, size_t k, size_t start, size_t end, pivot_ind_selector_func_t pivot_selector) {
    size_t step = (end - start) / (k - 1);
    int check[k];
    int check_indices[k];

    for (size_t i = 0; i < k; i++) {
        // Start doubles as pointer for array value to check
        check[i] = arr[start];
        check_indices[i] = start;
        start += step;
    }

    return check_indices[median_quickselect_standard(check, k, pivot_selector)];
}

// General function for median of k values with evenly split indices (operates on index array)
size_t pivot_median_k_split_ind(int *arr, size_t *indices, size_t k, size_t start, size_t end, pivot_ind_selector_func_t pivot_selector) {
    size_t step = (end - start) / (k - 1);
    int check[k];
    int check_indices[k];

    //printf("     Split: ");
    for (size_t i = 0; i < k; i++) {
        // Start doubles as pointer for array value to check
        check[i] = arr[indices[start]];
        check_indices[i] = start;
        //printf("%d(%d) ", arr[indices[start]], start);
        start += step;
    }
    //printf("\n");

    return check_indices[median_quickselect_standard(check, k, pivot_selector)];;
}

// Pivot on median of 3 values with evenly split indices
size_t pivot_median_3_split(int *arr, size_t start, size_t end) {
    size_t mid = start + (end - start) / 2;
    if (arr[start] > arr[mid]) {
        if (arr[start] < arr[end]) {
            return start;
        }
        if (arr[mid] > arr[end]) {
            return mid;
        }
        return end;
    }
    if (arr[mid] < arr[end]) {
        return mid;
    }
    if (arr[start] > arr[end]) {
        return start;
    }
    return end;
}

// Pivot on median of 3 values with evenly split indices (operates on index array)
size_t pivot_median_3_split_ind(int *arr, size_t *indices, size_t start, size_t end) {
    size_t mid = start + (end - start) / 2;
    if (arr[indices[start]] > arr[indices[mid]]) {
        if (arr[indices[start]] < arr[indices[end]]) {
            return start;
        }
        if (arr[indices[mid]] > arr[indices[end]]) {
            return mid;
        }
        return end;
    }
    if (arr[indices[mid]] < arr[indices[end]]) {
        return mid;
    }
    if (arr[indices[start]] > arr[indices[end]]) {
        return start;
    }
    return end;
}

// Pivot on median of 5 values with evenly split indices
size_t pivot_median_5_split(int *arr, size_t start, size_t end) {
    // TO-DO: Hardcode
    return pivot_median_k_split(arr, 5, start, end, pivot_median_5_split_ind);
}

// Pivot on median of 5 values with evenly split indices (operates on index array)
size_t pivot_median_5_split_ind(int *arr, size_t *indices, size_t start, size_t end) {
    // TO-DO: Hardcode
    if (start + 5 > end) {
        if (start + 3 > end) { return end; }
        return pivot_median_3_split_ind(arr, indices, start, end);
    }
    return pivot_median_k_split_ind(arr, indices, 5, start, end, pivot_median_5_split_ind);
}

// Pivot on median of cube root of n values with evenly split indices
size_t pivot_median_crn_split(int *arr, size_t start, size_t end) {
    size_t count = pow(end - start, 1.0/3.0);
    count -= count % 2 ? 0 : 1;
    if (count == 3) { return pivot_median_3_split(arr, start, end); }
    else if (count < 3) { return end; }
    return pivot_median_k_split(arr, count, start, end, pivot_median_crn_split_ind);
}

// Pivot on median of cube root of n values with evenly split indices (operates on index array)
size_t pivot_median_crn_split_ind(int *arr, size_t *indices, size_t start, size_t end) {
    size_t count = pow(end - start, 1.0/3.0);
    count -= count % 2 ? 0 : 1;
    if (count == 3) { return pivot_median_3_split_ind(arr, indices, start, end); }
    else if (count < 3) { return end; }
    return pivot_median_k_split_ind(arr, indices, count, start, end, pivot_median_crn_split_ind);
}

// General function for median of k values from randomly selected indices
size_t pivot_median_k_random(int *arr, size_t k, size_t start, size_t end, pivot_ind_selector_func_t pivot_selector) {
    int *check_indices = gen_random_arr(k, start, end - start + 1);
    int check[k];

    for (size_t i = 0; i < k; i++) {
        check[i] = arr[check_indices[i]];
    }

    size_t r = check_indices[median_quickselect_standard(check, k, pivot_selector)];
    free(check_indices);

    return r;
}

// General function for median of k values from randomly selected indices (operates on index array)
size_t pivot_median_k_random_ind(int *arr, size_t *indices, size_t k, size_t start, size_t end, pivot_ind_selector_func_t pivot_selector) {
    int *check_indices = gen_random_arr(k, start, end - start + 1);
    int check[k];

    for (size_t i = 0; i < k; i++) {
        check[i] = arr[indices[check_indices[i]]];
    }

    size_t r = check_indices[median_quickselect_standard(check, k, pivot_selector)];
    free(check_indices);

    return r;
}

// Pivot on median of 3 randomly selected values
size_t pivot_median_3_random(int *arr, size_t start, size_t end) {
    // TO-DO: Update to custom random

    size_t len = end - start + 1;
    size_t a = start + (rand() % len);
    size_t b = start + (rand() % len);
    size_t c = start + (rand() % len);

    if (arr[a] > arr[b]) {
        if (arr[a] < arr[c]) {
            return a;
        }
        if (arr[b] > arr[c]) {
            return b;
        }
        return c;
    }
    if (arr[b] < arr[c]) {
        return b;
    }
    if (arr[a] > arr[c]) {
        return a;
    }
    return c;
}

// Pivot on median of 3 randomly selected values (operates on index array)
size_t pivot_median_3_random_ind(int *arr, size_t *indices, size_t start, size_t end) {
    // TO-DO: Update to custom random

    size_t len = end - start + 1;
    size_t a = start + (rand() % len);
    size_t b = start + (rand() % len);
    size_t c = start + (rand() % len);

    if (arr[indices[a]] > arr[indices[b]]) {
        if (arr[indices[a]] < arr[indices[c]]) {
            return a;
        }
        if (arr[indices[b]] > arr[indices[c]]) {
            return b;
        }
        return c;
    }
    if (arr[indices[b]] < arr[indices[c]]) {
        return b;
    }
    if (arr[indices[a]] > arr[indices[c]]) {
        return a;
    }
    return c;
}

// Pivot on median of 5 randomly selected values
size_t pivot_median_5_random(int *arr, size_t start, size_t end) {
    // TO-DO: Hardcode
    return pivot_median_k_random(arr, 5, start, end, pivot_median_5_random_ind);
}

// Pivot on median of 5 randomly selected values (operates on index array)
size_t pivot_median_5_random_ind(int *arr, size_t *indices, size_t start, size_t end) {
    // TO-DO: Hardcode
    if (start + 5 > end) {
        if (start + 3 > end) { return end; }
        return pivot_median_3_random_ind(arr, indices, start, end);
    }
    return pivot_median_k_random_ind(arr, indices, 5, start, end, pivot_median_5_random_ind);
}

// Pivot on median of cube root of n randomly selected values
size_t pivot_median_crn_random(int *arr, size_t start, size_t end) {
    size_t count = pow(end - start, 1.0/3.0);
    count -= count % 2 ? 0 : 1;
    if (count == 3) { return pivot_median_3_random(arr, start, end); }
    else if (count < 3) { return end; }
    return pivot_median_k_random(arr, count, start, end, pivot_median_crn_random_ind);
}

// Pivot on median of cube root of n randomly selected values (operates on index array)
size_t pivot_median_crn_random_ind(int *arr, size_t *indices, size_t start, size_t end) {
    size_t count = pow(end - start, 1.0/3.0);
    count -= count % 2 ? 0 : 1;
    if (count == 3) { return pivot_median_3_random_ind(arr, indices, start, end); }
    else if (count < 3) { return end; }
    return pivot_median_k_random_ind(arr, indices, count, start, end, pivot_median_crn_random_ind);
}
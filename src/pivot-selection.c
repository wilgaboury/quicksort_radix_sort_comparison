//
// Created by Calvin Hirsch on 11/20/2019.
//

// MEDIAN FINDING METHODS (return index of median)

// Quickselect method using indices array to keep track of changing value locations and return index without modifying original array
size_t median_quickselect_helper(int *arr, size_t *indices, size_t start, size_t end, size_t middle, size_t (*pivot_selector)(int*, size_t, size_t)) {
    // TO-DO: Actually use pivot_selector, doesn't work regularly due to indices array
    size_t start_large, start_unvisited, pivot_ind;
    size_t temp, pivot;

    if (start + 1 < end) {
        start_large = start;
        start_unvisited = start;
        pivot_ind = end;
        pivot = arr[indices[pivot_ind]];

        while (start_unvisited < pivot_ind) {
            // If current item is less than pivot, swap it with the first element of the large array
            if (arr[indices[start_unvisited]] < pivot) {
                temp = indices[start_large];
                indices[start_large] = indices[start_unvisited];
                indices[start_unvisited] = temp;
                start_large++;
            }

            start_unvisited++;
        }

        temp = indices[pivot_ind];
        indices[pivot_ind] = indices[start_large];
        indices[start_large] = temp;

        // start_large is now the pivot location
        if (start_large < middle) { median_quickselect_helper(arr, indices, start_large + 1, end, middle, pivot_selector); }
        else if (start_large > middle) { median_quickselect_helper(arr, indices, start, start_large - 1, middle, pivot_selector); }
        else return indices[start_large];
    }
    else if (start < end) {
        if (start == middle) { return indices[start]; }
        else { return indices[end]; }
    }
}

size_t median_quickselect(int *arr, size_t len, size_t (*pivot_selector)(int*, size_t, size_t)) {
    // TO-DO: Find fastest way of quickselecting, currently standard quicksort
    size_t indices[len];
    for (int i = 0; i < len; i++) { indices[i] = i; }
    return median_quickselect_helper(arr, indices, 0, len - 1, len / 2, pivot_selector);
}


// PIVOT SELECTION METHODS (return index of pivot)

size_t pivot_end(int *arr, size_t start, size_t end) {
    return end;
}

size_t pivot_median_3_split(int *arr, size_t start, size_t end) {
    int step = (end - start) / 2;
    int check[3];
    int check_indices[3];

    for (int i = 0; i < 3; i++) {
        // Start doubles as pointer for array value to check
        check[i] = arr[start];
        check_indices[i] = start;
        start += step;
    }

    return check_indices[median_quickselect(check, 3, pivot_median_3_split)];
}

size_t pivot_median_5_split(int *arr, size_t start, size_t end) {
    int step = (end - start) / 4;
    int check[5];
    int check_indices[5];

    for (int i = 0; i < 5; i++) {
        // Start doubles as pointer for array value to check
        check[i] = arr[start];
        check_indices[i] = start;
        start += step;
    }

    return check_indices[median_quickselect(check, 5, pivot_median_5_split)];
}

size_t pivot_median_random(int *arr, size_t start, size_t end, size_t num_to_check) {

}
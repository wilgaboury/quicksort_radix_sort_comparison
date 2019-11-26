//
// Created by Calvin Hirsch on 10/29/2019.
//

void quicksort_stdlib (int *arr, size_t start, size_t end, pivot_selector_func_t pivot_selector) {
    qsort((arr + start), end - start + 1, sizeof(int), );
}

void quicksort_standard (int *arr, size_t start, size_t end, pivot_selector_func_t pivot_selector) {
    size_t start_large, start_unvisited, pivot_ind;
    int temp, pivot;

    if (start + 1 < end) {
        start_large = start;
        start_unvisited = start;
        pivot_ind = pivot_selector(arr, start, end);
        pivot = arr[pivot_ind];

        while (start_unvisited < pivot_ind) {
            // If current item is less than pivot, swap it with the first element of the large array
            if (arr[start_unvisited] < pivot) {
                temp = arr[start_large];
                arr[start_large] = arr[start_unvisited];
                arr[start_unvisited] = temp;
                start_large++;
            }

            start_unvisited++;
        }

        arr[pivot_ind] = arr[start_large];
        arr[start_large] = pivot;

        // start_large is now pivot location
        if (start_large) { quicksort_standard(arr, start, start_large - 1, pivot_selector); }
        quicksort_standard(arr, start_large + 1, end, pivot_selector);
    }
    else if (start < end) {
        if (arr[start] > arr[end]) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
}

void quicksort_out_in (int *arr, size_t start, size_t end, size_t (*pivot_selector)(int*, size_t, size_t)) {
    if (start + 1 < end) {
        int left, right, pivot, pivot_ind, temp;
        left = start;
        right = end - 1;
        pivot_ind = pivot_selector(arr, start, end);
        pivot = arr[pivot_ind];
        arr[pivot_ind] = arr[end];
        arr[end] = pivot;

        // Build small array from the left and large list from the right (pivot on last element)
        while (left < right) {
            if (arr[left] > pivot) {
                // When left element belongs in large list, move right pointer in until a value that belongs in the small list is found
                while (arr[right] >= pivot) { right--; }
                if (left < right) {
                    // Swap left and right elements, move both in
                    temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;

                    left++;
                    right--;
                }
            }
            else if (arr[right] < pivot) {
                // When right element belongs in small list, move left pointer in until a value that belongs in the large list is found
                while (arr[left] <= pivot) { left++; }
                if (left < right) {
                    // Swap left and right elements, move both in
                    temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;

                    left++;
                    right--;
                }
            }
            else {
                left++;
                right--;
            }
        }

        // Check if right is "overshot" and adjust if necessary
        if (right < start) { right = start; }
        if (arr[right] < pivot) { right++; }
        arr[end] = arr[right];
        arr[right] = pivot;
        // right now points to pivot

        if (right != start) { quicksort_out_in(arr, start, right - 1, pivot_selector); }
        quicksort_out_in(arr, right + 1, end, pivot_selector);
    }
    else if (start < end) {
        if (arr[start] > arr[end]) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
}
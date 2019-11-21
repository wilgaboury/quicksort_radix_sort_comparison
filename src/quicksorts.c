//
// Created by Calvin Hirsch on 10/29/2019.
//

void quicksort_standard (int *arr, size_t start, size_t end, size_t (*pivot_selector)(int*, size_t, size_t)) {
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

void quicksort_out_in (int *arr, size_t start, size_t end) {
    int left, right, pivot;

}
//
// Created by Calvin Hirsch on 10/29/2019.
//

#include "tester.h"
#include "pivot_selection.h"
#include "quicksorts.h"

int main() {
    validate_median(median_quickselect_standard, 1000, pivot_end_ind);
    validate_median(median_quickselect_standard, 1000, pivot_median_3_split_ind);
    validate_median(median_quickselect_standard, 1000, pivot_median_5_split_ind);
    validate_median(median_quickselect_standard, 1000, pivot_median_crn_split_ind);
    validate_median(median_quickselect_standard, 1000, pivot_median_3_random_ind);
    validate_median(median_quickselect_standard, 1000, pivot_median_5_random_ind);
    validate_median(median_quickselect_standard, 10000, pivot_median_crn_random_ind);

    validate_quicksort(quicksort_stdlib, 1000, pivot_end);
    validate_quicksort(quicksort_standard, 1000, pivot_end);
    validate_quicksort(quicksort_out_in, 1000, pivot_end);
    validate_quicksort(quicksort_out_in, 1000, pivot_median_3_split);
    validate_quicksort(quicksort_out_in, 1000, pivot_median_5_split);
    validate_quicksort(quicksort_out_in, 1000, pivot_median_crn_split);
    validate_quicksort(quicksort_out_in, 1000, pivot_median_3_random);
    validate_quicksort(quicksort_out_in, 1000, pivot_median_5_random);
    validate_quicksort(quicksort_out_in, 1000, pivot_median_crn_random);


    return 0;
}
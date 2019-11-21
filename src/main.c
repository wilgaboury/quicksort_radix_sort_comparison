//
// Created by Calvin Hirsch on 10/29/2019.
//

#include <stdio.h>
#include "quicksorts.c"
#include "tester.c"
#include "pivot-selection.c"

int main() {
    validate_quicksort(quicksort_standard, 1000, pivot_end);
    validate_median(median_quickselect, 1000, pivot_end);

    return 0;
}
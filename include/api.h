//
// Created by wilg on 11/22/19.
//

#include <stdint.h>

#ifndef QUICKSORT_RADIX_SORT_COMPARISON_API_H
#define QUICKSORT_RADIX_SORT_COMPARISON_API_H

typedef struct _TestData {
    unsigned long long computation_time;
} TestData;

extern TestData test_api(int input);

#endif //QUICKSORT_RADIX_SORT_COMPARISON_API_H

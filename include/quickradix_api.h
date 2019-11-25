//
// Created by wilg on 11/22/19.
//

#include <stdint.h>

#include "quicksorts.h"

#ifndef QUICKSORT_RADIX_SORT_COMPARISON_API_H
#define QUICKSORT_RADIX_SORT_COMPARISON_API_H

typedef struct _test_data {
    unsigned long long a;
    unsigned long long b;
} test_data;

extern test_data * get_test_data(unsigned long long a, unsigned long long b);
extern void free_test_data(test_data * data);

#endif //QUICKSORT_RADIX_SORT_COMPARISON_API_H

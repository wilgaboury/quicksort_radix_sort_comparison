//
// Created by wilg on 11/22/19.
//

#include <stdlib.h>
#include <time.h>

#include "../include/quickradix_api.h"

extern test_data * get_test_data(unsigned long long a, unsigned long long b) {
    test_data * result = malloc(sizeof(test_data));
    result->a = a;
    result->b = b;
    return result;
}

extern void free_test_data(test_data * data) {
    free(data);
}
//
// Created by wilg on 11/22/19.
//

#include <stdlib.h>
#include <time.h>

#include "../include/api.h"

extern TestData test_api(int input) {
    TestData result;
    if (input > RAND_MAX) {
        result.computation_time = 0;
        return result;
    }

    srand(time(0));
    result.computation_time = rand() % input;
    return result;
}
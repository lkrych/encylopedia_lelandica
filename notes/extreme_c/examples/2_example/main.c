#include <stdio.h>

#include "average.h"

int main(int argc, char** argv) {
    int array[5];

    array[0] = 10;
    array[1] = 3;
    array[2] = 5;
    array[3] = -8;
    array[4] = 9;

    double avg = average(array, 5, NORMAL);
    printf("The average: %f\n", avg);

    avg = average(array, 5, SQUARED);
    printf("The squared average: %f\n", avg);
    return 0;
}
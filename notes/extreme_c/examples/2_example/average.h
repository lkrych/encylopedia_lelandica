#ifndef EXAMPLE_AVERAGE
#define EXAMPLE_AVERAGE 
typedef enum{
    NONE,
    NORMAL,
    SQUARED
} average_type_t;

double average(int*, int, average_type_t);
#endif
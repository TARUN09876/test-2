// data_processor.c
#include <stdio.h>
#include <stdlib.h>
#include "data_processor.h"

int* generate_large_data(int size) {
    // Memory Leak: Allocating large data without tracking for free
    int *data = malloc(size * sizeof(int));
    
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 1000;
    }
    
    return data;
}

void process_data(int *data, int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    printf("Data sum: %lld\n", sum);
    
    // Memory Leak: Not freeing the input data
}

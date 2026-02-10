#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

void fill_random(float *arr, int rows, int cols) {
    printf("Generated Array (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i * cols + j] = (float)rand() / RAND_MAX * 10.0f;
            printf("%5.2f ", arr[i * cols + j]);
        }
        printf("\n");
    }
}

void search_indices(float *arr, int rows, int cols, float target) {
    int found = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // fabs -lm linking
            if (fabs(arr[i * cols + j] - target) < 0.01) {
                printf("Found at index [%d][%d]\n", i, j);
                found = 1;
            }
        }
    }
    if (!found) printf("Value not found.\n");
}
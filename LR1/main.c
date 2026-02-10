#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <rows> <cols>\n", argv[0]);
        return 1;
    }

    int dimA = atoi(argv[1]);
    int dimB = atoi(argv[2]);
    float target;
    
    if (dimA <= 0 || dimB <= 0) return 1;

    float* arr = (float*)malloc(dimA * dimB * sizeof(float));
    if (!arr) return 1;

    srand(time(NULL));

    fill_random(arr, dimA, dimB);

    printf("\nEnter value to search: ");
    if (scanf("%f", &target) != 1) {
        free(arr);
        return 1;
    }

    search_indices(arr, dimA, dimB, target);

    free(arr);
    return 0;
}
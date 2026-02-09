#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void search_indices(float *arr, int rows, int cols, float target) {
    int found = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fabs(arr[i * cols + j] - target) < 0.01) {
                printf("Found at index [%d][%d]\n", i, j);
                found = 1;
            }
        }
    }
    if (!found) printf("Value not found.\n");
}

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

    printf("Generated Array (%dx%d):\n", dimA, dimB);
    for (int i = 0; i < dimA; i++) {
        for (int j = 0; j < dimB; j++) {
            arr[i * dimB + j] = (float)rand() / RAND_MAX * 10.0f;
            printf("%5.2f ", arr[i * dimB + j]);
        }
        printf("\n");
    }

    printf("\nEnter value to search: ");
    scanf("%f", &target);

    search_indices(arr, dimA, dimB, target);

    free(arr);
    return 0;
}
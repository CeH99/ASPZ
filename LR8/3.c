#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void measure_time(int *arr, const char *test_name) {
    clock_t start = clock();
    qsort(arr, SIZE, sizeof(int), compare);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time of running (%s): %f sec\n", test_name, time_spent);
}

int main() {
    int *arr = malloc(SIZE * sizeof(int));

    // Test 1
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % SIZE;
    measure_time(arr, "Random data");

    // Test 2
    for (int i = 0; i < SIZE; i++) arr[i] = i;
    measure_time(arr, "Sorted array");

    // Test 3
    for (int i = 0; i < SIZE; i++) arr[i] = SIZE - i;
    measure_time(arr, "Reverse order");

    // Test 4
    for (int i = 0; i < SIZE; i++) arr[i] = 42;
    measure_time(arr, "Same elements");

    free(arr);
    return 0;
}
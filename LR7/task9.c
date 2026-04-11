#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dummy_work() {
    volatile long long sum = 0; // 'volatile' prevents compiler from optimizing the loop away
    for (long long i = 0; i < 50000000; i++) {
        sum += i;
    }
}

int main() {
    struct timespec start, end;
    double elapsed_ms;

    clock_gettime(CLOCK_MONOTONIC, &start);

    dummy_work();

    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed_ms = (end.tv_sec - start.tv_sec) * 1000.0 + 
                    (end.tv_nsec - start.tv_nsec) / 1000000.0;

    printf("Execution time: %.3f ms\n", elapsed_ms);

    return EXIT_SUCCESS;
}
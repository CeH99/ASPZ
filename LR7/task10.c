#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Generate random float between 0.0 and 1.0
float rand_float() {
    return (float)rand() / (float)RAND_MAX;
}

// Generate random float between 0.0 and n
float rand_float_n(float n) {
    return rand_float() * n;
}

int main() {
    srand(time(NULL) ^ getpid());

    float n = 7.5f;

    printf("Random [0.0, 1.0]: %.4f\n", rand_float());
    printf("Random [0.0, %.1f]: %.4f\n", n, rand_float_n(n));

    return EXIT_SUCCESS;
}
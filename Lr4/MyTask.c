#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Визначаємо розмір блоку: 1 Гігабайт
#define SIZE (1024L * 1024L * 1024L)

// Допоміжна функція для отримання поточного часу в секундах
double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main() {
    double start, end;
    double time_calloc, time_malloc;

    printf("Виділення великого блоку пам'яті: %ld байт (1 ГБ)\n\n", SIZE);

    // --- Тест 1: calloc ---
    start = get_time();
    void *ptr_calloc = calloc(1, SIZE);
    end = get_time();
    time_calloc = end - start;
    
    if (!ptr_calloc) {
        perror("calloc failed");
        return 1;
    }
    printf("1. Час виконання calloc(): %f секунд\n", time_calloc);
    free(ptr_calloc);

    // --- Тест 2: malloc + memset ---
    start = get_time();
    void *ptr_malloc = malloc(SIZE);
    if (!ptr_malloc) {
        perror("malloc failed");
        return 1;
    }
    memset(ptr_malloc, 0, SIZE);
    end = get_time();
    time_malloc = end - start;
    
    printf("2. Час виконання malloc() + memset(): %f секунд\n", time_malloc);
    free(ptr_malloc);

    // Висновок
    if (time_calloc > 0) {
        printf("\ncalloc виявився у %.2f разів швидшим.\n", time_malloc / time_calloc);
    }

    return 0;
}
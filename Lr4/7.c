#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

struct sbar {
    int data[10];
};

int main() {
    struct sbar *ptr, *newptr;

    // 1. Початкове виділення пам'яті через calloc
    ptr = calloc(1000, sizeof(struct sbar));
    if (ptr == NULL) {
        perror("calloc failed");
        return 1;
    }

    // 2. Зміна розміру пам'яті через reallocarray (безпечний варіант)
    // Замість: newptr = realloc(ptr, 500 * sizeof(struct sbar));
    newptr = reallocarray(ptr, 500, sizeof(struct sbar));

    if (newptr == NULL) {
        perror("reallocarray failed");
        free(ptr);
        return 1;
    }
    free(newptr);
    
    return 0;
}
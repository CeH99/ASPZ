#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Calling malloc(0)...\n");
    void *ptr = malloc(0);

    if (ptr == NULL) {
        printf("malloc(0) returned NULL.\n");
    } else {
        printf("malloc(0) returned a valid pointer: %p\n", ptr);
        // Вказівник, що не є NULL, обов'язково треба передати у free()
        free(ptr);
        printf("Memory freed successfully.\n");
    }

    return 0;
}
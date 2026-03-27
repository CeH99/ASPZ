#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    size_t max_size = (size_t)-1;
    printf("Max size_t value: %zu bytes\n", max_size);

    // Спроба виділити максимальний обсяг пам'яті
    void *ptr = malloc(max_size);
    if (ptr == NULL) {
        printf("malloc failed to allocate %zu bytes as expected.\n", max_size);
    } else {
        printf("malloc succeeded! (Unexpected)\n");
        free(ptr);
    }

    return 0;
}
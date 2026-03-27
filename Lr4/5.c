#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    void *original_ptr = malloc(1024);
    if (original_ptr == NULL) {
        printf("Помилка початкового виділення пам'яті.\n");
        return 1;
    }
    printf("Початковий блок (1 KB) виділено за адресою: %p\n", original_ptr);

    size_t huge_size = (size_t)-1;
    printf("Спроба realloc до розміру %zu байт...\n", huge_size);
    
    void *new_ptr = realloc(original_ptr, huge_size);

    if (new_ptr == NULL) {
        printf("realloc повернув NULL (не зміг виділити пам'ять).\n");
        printf("АЛЕ оригінальний вказівник залишається дійсним: %p\n", original_ptr);
        
        free(original_ptr);
        printf("Оригінальний блок успішно звільнено.\n");
    } else {
        printf("realloc несподівано спрацював!\n");
        free(new_ptr);
    }

    return 0;
}
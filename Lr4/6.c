#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("--- Тест 1: realloc(NULL, size) ---\n");
    // Виклик realloc з NULL діє як malloc
    void *ptr = realloc(NULL, 1024);
    
    if (ptr != NULL) {
        printf("Успіх: realloc(NULL, 1024) відпрацював як malloc(1024).\n");
        printf("Пам'ять виділено за адресою: %p\n", ptr);
    } else {
        printf("Помилка: не вдалося виділити пам'ять.\n");
        return 1;
    }

    printf("\n--- Тест 2: realloc(ptr, 0) ---\n");
    // Виклик realloc з розміром 0 діє як free(ptr)
    void *new_ptr = realloc(ptr, 0);
    
    if (new_ptr == NULL) {
        printf("Результат: realloc(ptr, 0) повернув NULL.\n");
        printf("Пам'ять за адресою %p була успішно звільнена (аналог free).\n", ptr);
    } else {
        printf("Результат: realloc(ptr, 0) повернув адресу %p.\n", new_ptr);
        free(new_ptr); // На випадок, якщо реалізація повертає вказівник-заглушку
    }

    return 0;
}
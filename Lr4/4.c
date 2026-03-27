#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void run_buggy_version() {
    printf("--- Запуск версії з ПОМИЛКОЮ (закоментовано, щоб уникнути краху) ---\n");
    /*
    int n = 100;
    void *ptr = NULL;
    int iterations = 0;
    
    while (iterations < 2) {
        if (!ptr) {
            ptr = malloc(n);
            printf("Ітерація %d: Виділено пам'ять за адресою %p\n", iterations, ptr);
        }
        
        // Використання 'ptr'
        printf("Ітерація %d: Робота з пам'яттю...\n", iterations);
        
        free(ptr);
        printf("Ітерація %d: Пам'ять звільнено.\n", iterations);
        
        iterations++;
    }
    */
    printf("Цей код викликав би помилку 'double free or corruption' на другій ітерації.\n\n");
}

void run_fixed_version() {
    printf("--- Запуск ВИПРАВЛЕНОЇ версії ---\n");
    int n = 100;
    void *ptr = NULL;
    int iterations = 0;
    
    while (iterations < 2) {
        if (!ptr) {
            ptr = malloc(n);
            printf("Ітерація %d: Виділено пам'ять за адресою %p\n", iterations, ptr);
        }
        
        // Використання 'ptr'
        printf("Ітерація %d: Робота з пам'яттю...\n", iterations);
        
        free(ptr);
        printf("Ітерація %d: Пам'ять звільнено.\n", iterations);
        
        // !!! занулюємо вказівник
        ptr = NULL; 
        
        iterations++;
    }
}

int main() {
    run_buggy_version();
    run_fixed_version();
    return 0;
}
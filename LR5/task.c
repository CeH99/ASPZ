#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    size_t initial_size = 100 * sizeof(int);
    int *ptr = malloc(initial_size); 

    if (ptr == NULL) {
        printf("Error: Initial memory allocation failed.\n");
        return 1;
    }

    ptr[0] = 42; 
    printf("Data before realloc: %d\n", ptr[0]);
    printf("Address before realloc: %p\n", (void*)ptr);

    size_t impossible_size = SIZE_MAX; 
    
    ptr = realloc(ptr, impossible_size); 

    if (ptr == NULL) {
    
        printf("\nrealloc failed (returned NULL).\n");
        printf("Pointer 'ptr' is now NULL. Access to original data is lost!\n");
        
    }

    return 0; 
}
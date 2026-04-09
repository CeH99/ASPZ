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

    // Write some data to the allocated memory
    ptr[0] = 42; 
    printf("Data before realloc: %d\n", ptr[0]);
    printf("Address before realloc: %p\n", (void*)ptr);

    // 2. Incorrect realloc call
    // Requesting an impossible amount of memory to force a failure
    size_t impossible_size = SIZE_MAX; 
    
    // ERROR: Overwriting the only pointer to our data directly
    ptr = realloc(ptr, impossible_size); 

    // 3. Check the consequences
    if (ptr == NULL) {
        // realloc returned NULL, original data is untouched but inaccessible
        printf("\nrealloc failed (returned NULL).\n");
        printf("Pointer 'ptr' is now NULL. Access to original data is lost!\n");
        
        // Cannot call free() because the original address is gone -> Memory Leak
    }

    return 0; 
}
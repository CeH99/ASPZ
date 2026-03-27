#include <stdio.h>
#include <stdlib.h>

int main() {
    int xa = 1000000;
    int xb = 3000;
    
    int num = xa * xb; 
    
    printf("xa = %d, xb = %d\n", xa, xb);
    printf("Signed num (xa * xb) = %d\n", num); 
    
    printf("Unsigned interpretation in size_t: %zu\n", (size_t)num);
    void *ptr = malloc(num);
    
    if (ptr == NULL) {
        printf("Result: malloc failed and returned NULL as expected.\n");
    } else {
        printf("Result: malloc succeeded! (Unexpected)\n");
        free(ptr);
    }
    
    return 0;
}
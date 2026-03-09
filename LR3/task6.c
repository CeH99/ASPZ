#include <stdio.h>

// A recursive function that allocates memory on the stack
void recursive_function(int depth) {
    // Allocate 10 KB on the stack per call to quickly hit the limit
    char stack_eater[10240]; 
    
    printf("Recursion depth: %d\n", depth);
    
    // Modify the array slightly to prevent the compiler from optimizing it away
    stack_eater[0] = (char)depth; 
    
    // Call itself, going deeper into the stack
    recursive_function(depth + 1);
}

int main() {
    printf("Starting recursion to demonstrate stack limit...\n");
    recursive_function(1);
    
    return 0;
}
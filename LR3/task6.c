#include <stdio.h>

void recursive_function(int depth) {
    char stack_eater[10240]; 
    
    printf("Recursion depth: %d\n", depth);
    
    stack_eater[0] = (char)depth; 
    
    recursive_function(depth + 1);
}

int main() {
    printf("Starting recursion to demonstrate stack limit...\n");
    recursive_function(1);
    
    return 0;
}
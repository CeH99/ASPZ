#include <stdio.h>
#include <stdlib.h>
int global_init = 1;      // data
int global_uninit;        // bss
void test_stack() { int j; printf("New Stack: %p\n", &j); }
int main() {
    int i;                // stack
    int *heap_ptr = malloc(4); // heap
    printf("Stack: %p\nHeap: %p\nData: %p\nBSS: %p\n", &i, heap_ptr, &global_init, &global_uninit);
    test_stack();
    return 0;
}
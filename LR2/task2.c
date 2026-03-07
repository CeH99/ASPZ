#include <stdio.h>

//BSS increasing
//int global_uninit[1000];


//BSS -> data
//int global_init[1000] = {1};


void local_function() {
    //Wont affect bcs its in stack

    //int local_uninit[1000];
    //int local_init[1000] = {1};
    
    printf("Функція виконана.\n");
}

int main() {
    printf("Hello World!\n");
    
    local_function();
    return 0;
}
#include <stdio.h>
#include <limits.h>

int check_overflow(int x) {
    int step = 1;
    int y = x + step;
    
    if (y < x) {
        return 1;
    }
    return 0;
}

int main() {
    int val = INT_MAX; 

    if (check_overflow(val)) {
        printf("Result: Overflow occurred!\n");
    } else {
        printf("Result: No overflow, check optimized out.\n");
    }

    return 0;
}
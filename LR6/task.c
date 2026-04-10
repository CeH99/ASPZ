#include <stdio.h>
#include <limits.h>

int check_overflow(int x) {
    // Signed integer overflow is UB.
    // Math: x + 1 > x. Compiler assumes this is ALWAYS true.
    if (x + 1 < x) {
        return 1;
    }
    return 0;
}

int main() {
    int val = INT_MAX; // Maximum value for int (2147483647)

    if (check_overflow(val)) {
        printf("Result: Overflow occurred!\n");
    } else {
        printf("Result: No overflow, check optimized out.\n");
    }

    return 0;
}
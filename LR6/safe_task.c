#include <stdio.h>
#include <limits.h>

int safe_add_check(int x) {
    if (x > INT_MAX - 1) {
        return 1;
    }
    return 0;
}

int main() {
    int val = INT_MAX;

    if (safe_add_check(val)) {
        printf("Result: Blocked potential overflow!\n");
    } else {
        int new_val = val + 1;
        printf("Result: Added safely.\n");
    }

    return 0;
}
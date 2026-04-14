#include <stdio.h>
#include <limits.h>

int safe_add_check(int x, int step) {
    if (x > INT_MAX - step) {
        return 1;
    }
    return 0;
}

int main() {
    int val = INT_MAX;
    int step = 1;

    if (safe_add_check(val, step)) {
        printf("Result: Blocked potential overflow!\n");
    } else {
        int y = val + step;
        printf("Result: Added safely.\n");
    }

    return 0;
}
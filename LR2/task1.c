#include <stdio.h>
#include <time.h>
#include <limits.h>

int main() {

    printf("Size of time_t: %zu bytes\n", sizeof(time_t));

    time_t max_time;

    if (sizeof(time_t) == 4) {
        max_time = 2147483647;
    } else {
        max_time = 9223372036854775807LL;
    }

    printf("Max time_t value (seconds): %lld\n", (long long)max_time);
    printf("Overflow date: %s", asctime(gmtime(&max_time)));

    return 0;
}
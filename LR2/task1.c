#include <stdio.h>
#include <time.h>

int main() {
    // calculating max of time_t
    time_t max_time = ~((time_t)1 << (sizeof(time_t) * 8 - 1));
    
    printf("Size of time_t: %zu bytes\n", sizeof(time_t));
    
    // trying to formate
    struct tm *time_info = gmtime(&max_time);
    
    if (time_info == NULL) {
        printf("Max time in sec: %lld\n", (long long)max_time);
        printf("Date is to far in the future (about 292 billions of years), gmtime() cant formate it\n");
    } else {
        printf("time_t will end in: %s", asctime(time_info));
    }
    
    return 0;
}
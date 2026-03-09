#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main() {
    int count = 0;
    int fd;

    printf("Starting to open file descriptors...\n");

    // Infinite loop to keep opening files until the system stops us
    while (1) {
        // We open /dev/null because we just need to consume a file descriptor, 
        // without actually writing data to the hard drive.
        fd = open("/dev/null", O_RDONLY);
        
        if (fd < 0) {
            // Check if the error is due to reaching the max open files limit (EMFILE)
            if (errno == EMFILE) {
                printf("\n[LIMIT REACHED]: Too many open files (EMFILE)!\n");
                printf("Total file descriptors successfully opened by this process: %d\n", count);
            } else {
                printf("\n[ERROR]: Failed to open file. Reason: %s\n", strerror(errno));
            }
            break; // Exit the loop since we can't open any more files
        }
        count++;
    }

    return 0;
}
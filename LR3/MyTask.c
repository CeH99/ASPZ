#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main() {
    int count = 0;
    int fd;

    printf("Starting to open file descriptors...\n");

    while (1) {
        fd = open("/dev/null", O_RDONLY); // returns number (discriptor)
        
        if (fd < 0) {
            
            if (errno == EMFILE) {
                printf("\n[LIMIT REACHED]: Too many open files (EMFILE)!\n");
                printf("Total file descriptors successfully opened by this process: %d\n", count);
            } else {
                printf("\n[ERROR]: Failed to open file. Reason: %s\n", strerror(errno));
            }
            break; 
        }
        count++;
    }

    return 0;
}
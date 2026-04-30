#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("test81.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) return 1;

    char buffer[] = "Test data for task 8.1";
    int nbytes = sizeof(buffer) - 1; 
    int count = write(fd, buffer, nbytes);

    if (count != nbytes) {
        printf("Writed less bytes: %d из %d\n", count, nbytes);
    } else {
        printf("Successfully writen %d bytes.\n", count);
    }
    close(fd);
    return 0;
}
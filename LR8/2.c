#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("data82.bin", O_RDWR | O_CREAT | O_TRUNC, 0644);
    char data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    write(fd, data, sizeof(data));

    lseek(fd, 3, SEEK_SET);

    char buffer[4];
    read(fd, buffer, 4);

    printf("Buffer data: ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    close(fd);
    return 0;
}
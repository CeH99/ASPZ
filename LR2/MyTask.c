#include <stdio.h>
#include <string.h>

void vulnerable(char *input) {
    char buffer[16];

    strcpy(buffer, input); // !!!
    printf("Buffer: %s\n", buffer);
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    vulnerable(argv[1]);

    return 0;
}
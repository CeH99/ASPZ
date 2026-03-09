#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_sigxfsz(int sig) {
    printf("\n[ERROR]: File size limit exceeded during write (SIGXFSZ)!\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    signal(SIGXFSZ, handle_sigxfsz);

    if (argc != 3) {
        printf("Program need two arguments\n");
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (!src) {
        printf("Cannot open file %s for reading\n", argv[1]);
        return 1;
    }

    FILE *dest = fopen(argv[2], "wb");
    if (!dest) {
        printf("Cannot open file %s for writing\n", argv[2]);
        fclose(src);
        return 1;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
        fflush(dest);
    }

    printf("File copied successfully.\n");
    
    fclose(src);
    fclose(dest);
    return 0;
}
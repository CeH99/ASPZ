#include <stdio.h>
#include <stdlib.h>

#define LINES_PER_PAGE 20
#define MAX_LINE_LENGTH 2048

void wait_for_user(FILE *tty) {
    printf("\033[7m--More--(Press Enter to continue)\033[0m");
    fflush(stdout);

    int c;
    while ((c = getc(tty)) != '\n' && c != EOF) {}
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2 ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char buffer[MAX_LINE_LENGTH];
    int line_count = 0;

    FILE *tty = fopen("/dev/tty", "r"); //!!!
    if (tty == NULL) {
        perror("Warning: Cannot open /dev/tty, falling back to stdin");
        tty = stdin;
    }

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            fprintf(stderr, "Error: Cannot open file '%s'\n", argv[i]);
            continue;
        }

        if (argc > 2) {
            printf("::::::::::::::\n%s\n::::::::::::::\n", argv[i]);
            line_count += 3;
        }

        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
            line_count++;

            if (line_count >= LINES_PER_PAGE) {
                wait_for_user(tty);
                line_count = 0;
            }
        }

        fclose(file);
    }

    if (tty != stdin) {
        fclose(tty);
    }

    return EXIT_SUCCESS;
}
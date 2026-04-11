#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2048

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <search_word> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *search_word = argv[1];
    char *filename = argv[2];
    char line[MAX_LINE_LENGTH];

    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error: Cannot open the file");
        return EXIT_FAILURE;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        // If the search word is found in the line, print the line
        if (strstr(line, search_word) != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);

    return EXIT_SUCCESS;
}
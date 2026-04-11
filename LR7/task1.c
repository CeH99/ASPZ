#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *rwho_fp, *more_fp;
    char buffer[1024];

    // Open the rwho process for reading its standard output
    rwho_fp = popen("who", "r");
    if (rwho_fp == NULL) {
        perror("Error: Failed to execute rwho");
        return EXIT_FAILURE;
    }

    // Open the more process for writing to its standard input
    more_fp = popen("more", "w");
    if (more_fp == NULL) {
        perror("Error: Failed to execute more");
        pclose(rwho_fp);
        return EXIT_FAILURE;
    }

    // Read data from rwho line by line and send it to more
    while (fgets(buffer, sizeof(buffer), rwho_fp) != NULL) {
        fputs(buffer, more_fp);
    }

    // Close the file streams and wait for processes to terminate
    pclose(rwho_fp);
    pclose(more_fp);

    return EXIT_SUCCESS;
}

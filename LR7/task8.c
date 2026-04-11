#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("Error: Cannot open directory");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    char response;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        printf("Delete '%s'? (y/n): ", entry->d_name);
        
        scanf(" %c", &response);
        while (getchar() != '\n'); 

        if (response == 'y' || response == 'Y') {
            if (unlink(entry->d_name) == 0) {
                printf("Success: Deleted %s\n", entry->d_name);
            } else {
                perror("Error: Cannot delete");
            }
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("Error: Cannot open directory");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    struct stat file_stat;
    uid_t my_uid = getuid(); 

    while ((entry = readdir(dir)) != NULL) {

        char *ext = strrchr(entry->d_name, '.');
        
        if (ext && strcmp(ext, ".c") == 0) {
            if (stat(entry->d_name, &file_stat) == 0) {
                if (file_stat.st_uid == my_uid) {
                    printf("File: %s\n", entry->d_name);
                    printf("Grant read permission to others? (y/n): ");
                    
                    char response;
                    scanf(" %c", &response);

                    while (getchar() != '\n'); 

                    if (response == 'y' || response == 'Y') {
                        if (chmod(entry->d_name, file_stat.st_mode | S_IROTH) == 0) {
                            printf("Success: Permissions updated for %s\n", entry->d_name);
                        } else {
                            perror("Error: Cannot update permissions");
                        }
                    }
                }
            }
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
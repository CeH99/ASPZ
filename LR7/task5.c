#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void list_dir(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) return;

    struct dirent *entry;
    char next_path[1024];

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." to avoid infinite loops
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Format the full path
        snprintf(next_path, sizeof(next_path), "%s/%s", path, entry->d_name);
        
        printf("%s\n", next_path);

        if (entry->d_type == DT_DIR) {
            list_dir(next_path);
        }
    }
    
    closedir(dir);
}

int main() {
    list_dir(".");
    return EXIT_SUCCESS;
}
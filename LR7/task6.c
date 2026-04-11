#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int filter_dirs(const struct dirent *entry) {
    if (entry->d_name[0] == '.') {
        return 0;
    }
    
    return entry->d_type == DT_DIR;
}

int main() {
    struct dirent **dir_list;
    int n;

    // scandir() reads ".", filters via filter_dirs, and sorts via alphasort
    n = scandir(".", &dir_list, filter_dirs, alphasort);

    if (n < 0) {
        perror("Error: Cannot read directory");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        printf("%s/\n", dir_list[i]->d_name);
        free(dir_list[i]);
    }
    
    free(dir_list);

    return EXIT_SUCCESS;
}
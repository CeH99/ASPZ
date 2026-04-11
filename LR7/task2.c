#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

// Function to print file permissions and type
void print_permissions(mode_t mode) {
    // File type
    if (S_ISDIR(mode)) printf("d");
    else if (S_ISLNK(mode)) printf("l");
    else if (S_ISCHR(mode)) printf("c");
    else if (S_ISBLK(mode)) printf("b");
    else if (S_ISFIFO(mode)) printf("p");
    else if (S_ISSOCK(mode)) printf("s");
    else printf("-");

    // Owner permissions
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");

    // Group permissions
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");

    // Other permissions
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    // Open current directory
    dir = opendir(".");
    if (dir == NULL) {
        perror("Error: Cannot open current directory");
        return EXIT_FAILURE;
    }

    // Read directory entries one by one
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get file statistics
        if (stat(entry->d_name, &file_stat) == -1) {
            perror("Error: Cannot get file stats");
            continue;
        }

        print_permissions(file_stat.st_mode);

        printf(" %lu", (unsigned long)file_stat.st_nlink);

        struct passwd *pw = getpwuid(file_stat.st_uid);
        if (pw != NULL) {
            printf(" %s", pw->pw_name);
        } else {
            printf(" %d", file_stat.st_uid);
        }

        struct group *gr = getgrgid(file_stat.st_gid);
        if (gr != NULL) {
            printf(" %s", gr->gr_name);
        } else {
            printf(" %d", file_stat.st_gid);
        }

        printf(" %5ld", (long)file_stat.st_size);

        char time_buf[80];
        struct tm *time_info = localtime(&file_stat.st_mtime);
        strftime(time_buf, sizeof(time_buf), "%b %d %H:%M", time_info);
        printf(" %s", time_buf);
        printf(" %s\n", entry->d_name);
    }
    
    closedir(dir);

    return EXIT_SUCCESS;
}
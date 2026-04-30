#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void test_special_file(const char* filepath) {
    printf("\n--- Тестування файлу: %s ---\n", filepath);
    
    int fd = open(filepath, O_RDWR);
    if (fd < 0) {
        perror("Помилка відкриття");
        return;
    }

    // Test 1
    off_t offset = lseek(fd, 100, SEEK_SET);
    if (offset == -1) perror("Помилка lseek (SEEK_SET)");
    else printf("lseek (SEEK_SET, 100) повернув зміщення: %ld\n", (long)offset);

    // Test 2
    offset = lseek(fd, 50, SEEK_CUR);
    if (offset == -1) perror("Помилка lseek (SEEK_CUR)");
    else printf("lseek (SEEK_CUR, 50) повернув зміщення: %ld\n", (long)offset);

    // Test 3
    offset = lseek(fd, 0, SEEK_END);
    if (offset == -1) perror("Помилка lseek (SEEK_END)");
    else printf("lseek (SEEK_END, 0) повернув зміщення: %ld\n", (long)offset);

    close(fd);
}

int main() {
    printf("Фреймворк тестування lseek() для спеціальних пристроїв\n");
    test_special_file("/dev/null");
    test_special_file("/dev/zero");
    return 0;
}
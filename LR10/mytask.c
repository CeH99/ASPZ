#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_process_tree(int current_level, int max_level) {
    // Виводимо інформацію про поточний процес
    printf("Рівень %d: PID = %d, Parent PID = %d\n", current_level, getpid(), getppid());

    // Якщо досягли максимального рівня, припиняємо розгалуження
    if (current_level >= max_level - 1) {
        return;
    }

    // Створюємо рівно 2 дочірніх процеси
    for (int i = 0; i < 2; i++) {
        pid_t pid = fork();
        
        if (pid < 0) {
            perror("Помилка створення процесу");
            exit(1);
        } else if (pid == 0) {
            // Дочірній процес викликає функцію для наступного рівня
            create_process_tree(current_level + 1, max_level);
            exit(0);
        }
    }

    for (int i = 0; i < 2; i++) {
        wait(NULL);
    }
}

int main() {
    printf("Початок побудови дерева процесів (3 рівні)...\n");
    printf("===========================================\n");
    
    // Викликаємо функцію з нульового рівня, всього 3 рівні
    create_process_tree(0, 3);
    
    if (getpid() != 0)
        sleep(1); 
    
    return 0;
}
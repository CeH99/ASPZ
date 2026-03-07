// vuln.c
#include <stdio.h>
#include <string.h>

void secret_function() {
    printf("\n[!] Exploit success!\n");
}

void process_input(char *input) {
    char buffer[16]; // Малий буфер
    strcpy(buffer, input); // Вразливість: копіювання без перевірки довжини
    printf("Ваш ввід: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc > 1) process_input(argv[1]);
    return 0;
}
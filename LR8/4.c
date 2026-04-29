#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;
    pid = fork();
    
    if (pid < 0) {
        printf("Error fork\n");
        return 1;
    }
    
    printf("%d\n", pid);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void handle_sigxcpu(int sig) {
    printf("\n[HANDLER]: CPU time limit exceeded (SIGXCPU). Stopping generation.\n");
    exit(0);
}

int main() {
    signal(SIGXCPU, handle_sigxcpu);
    srand(time(NULL));
    
    printf("Generating lottery (7 out of 49 and 6 out of 36)...\n");
    
    while(1) {
        for(int i = 0; i < 7; i++) {
            printf("%d ", (rand() % 49) + 1);
        }
        printf("| ");
        for(int i = 0; i < 6; i++) {
            printf("%d ", (rand() % 36) + 1);
        }
        printf("\n");
    }
    return 0;
}
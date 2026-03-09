#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigxfsz(int sig) {
    printf("\n[HANDLER]: File size limit reached (SIGXFSZ). Stopping write.\n");
    exit(0);
}

int main() {
    signal(SIGXFSZ, handle_sigxfsz); 
    
    FILE *file = fopen("dice_rolls.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    printf("Rolling the dice and writing to file...\n");
    
    while (1) {
        int roll = (rand() % 6) + 1;
        fprintf(file, "Roll: %d\n", roll);
        fflush(file);
    }
    
    fclose(file);
    return 0;
}
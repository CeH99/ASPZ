#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for exceeding file size limit
void handle_sigxfsz(int sig) {
    printf("\n[HANDLER]: File size limit reached (SIGXFSZ). Stopping write.\n");
    exit(0);
}

int main() {
    // Register the signal handler
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
        fflush(file); // Force write to disk to hit the limit faster
    }
    
    fclose(file);
    return 0;
}
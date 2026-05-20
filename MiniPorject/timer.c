#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

// Use sig_atomic_t for safe variable modification inside the signal handler
volatile sig_atomic_t elapsed_seconds = 0;

// Signal handler for SIGALRM
void timer_handler(int signum) {
    (void)signum;
    elapsed_seconds++;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_seconds>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int target_seconds = atoi(argv[1]);
    if (target_seconds <= 0) {
        fprintf(stderr, "Error: number of seconds must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    // Set up signal handler 
    struct sigaction sa;
    sa.sa_handler = timer_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("Error setting sigaction handler");
        exit(EXIT_FAILURE);
    }

    // Set up interval timer
    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    // Start the real-time timer
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("Error setting setitimer");
        exit(EXIT_FAILURE);
    }

    printf("Timer started for %d seconds...\n", target_seconds);

    // Main loop
    while (elapsed_seconds < target_seconds) {
        // pause() suspends the process until any signal is received
        pause();
        printf("Elapsed %d second(s)...\n", (int)elapsed_seconds);
    }

    printf("Timer finished (reached %d sec).\n", target_seconds);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void signal_handler(int sig) {
    int handler_local_var;
    
    printf("\n\n[Handler] Received signal %d (%s).\n", sig, strsignal(sig));
    printf("[Handler] Local variable address (Alternative stack): %p\n", (void*)&handler_local_var);
    printf("[Handler] Graceful shutdown...\n");
    exit(0);
}

int main() {
    int main_local_var;
    
    printf("--- sigaltstack Demonstration (Variant 8) ---\n");
    printf("Process PID: %d\n", getpid());
    printf("[Main thread] Local variable address (Main stack): %p\n", (void*)&main_local_var);

    stack_t alt_stack;
    alt_stack.ss_size = SIGSTKSZ;
    alt_stack.ss_sp = malloc(alt_stack.ss_size);
    alt_stack.ss_flags = 0;

    if (alt_stack.ss_sp == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    if (sigaltstack(&alt_stack, NULL) == -1) {
        perror("sigaltstack error");
        exit(1);
    }

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = signal_handler;
    sa.sa_flags = SA_ONSTACK; 
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction error (SIGINT)");
        exit(1);
    }
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("sigaction error (SIGTERM)");
        exit(1);
    }

    printf("\nHandlers set to alternative stack.\n");
    printf("Press Ctrl+C (or send SIGTERM via kill -TERM %d)...\n", getpid());

    while (1) {
        sleep(1);
        printf(".");
        fflush(stdout);
    }

    return 0; 
}
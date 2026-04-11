#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_JOBS 50
#define MAX_CMD_LEN 256

typedef struct {
    int min;
    int hour;
    char cmd[MAX_CMD_LEN];
} CronJob;

CronJob jobs[MAX_JOBS];
int job_count = 0;

void load_crontab(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error: Cannot open crontab file");
        exit(EXIT_FAILURE);
    }

    char line[512], min_str[10], hour_str[10];

    while (fgets(line, sizeof(line), file) && job_count < MAX_JOBS) {
        if (line[0] == '#' || line[0] == '\n') continue;

        if (sscanf(line, "%s %s %[^\n]", min_str, hour_str, jobs[job_count].cmd) == 3) {
            jobs[job_count].min = (strcmp(min_str, "*") == 0) ? -1 : atoi(min_str);
            jobs[job_count].hour = (strcmp(hour_str, "*") == 0) ? -1 : atoi(hour_str);
            job_count++;
        }
    }
    fclose(file);
    printf("Loaded %d jobs.\n", job_count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <crontab_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_crontab(argv[1]);

    int last_min = -1;
    printf("Foreground cron started. Press Ctrl+C to stop.\n");

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_min != last_min) {
            last_min = t->tm_min;

            for (int i = 0; i < job_count; i++) {
                int min_match = (jobs[i].min == -1 || jobs[i].min == t->tm_min);
                int hour_match = (jobs[i].hour == -1 || jobs[i].hour == t->tm_hour);

                if (min_match && hour_match) {
                    printf("[%02d:%02d] Executing: %s\n", t->tm_hour, t->tm_min, jobs[i].cmd);

                    if (system(jobs[i].cmd) == -1) {
                        perror("Error: Command execution failed");
                    }
                }
            }
        }

        sleep(1);
    }

    return EXIT_SUCCESS;
}
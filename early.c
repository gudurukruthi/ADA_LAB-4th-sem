#include <stdio.h>

#define MAX 10

// Structure for a process
typedef struct {
    int id;
    int arrival;
    int burst;
    int deadline;
    int remaining;
    int completion;
} Process;

void edf(Process p[], int n) {
    int time = 0, completed = 0;
    int min_deadline, idx;

    printf("\n--- Earliest Deadline First Scheduling ---\n");

    while (completed < n) {
        min_deadline = 100000;
        idx = -1;

        // Find process with earliest deadline among arrived processes
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0) {
                if (p[i].deadline < min_deadline) {
                    min_deadline = p[i].deadline;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            printf("Time %d: Executing P%d\n", time, p[idx].id);
            p[idx].remaining--;
            time++;

            // If process completes
            if (p[idx].remaining == 0) {
                p[idx].completion = time;
                completed++;
                printf("P%d completed at time %d\n", p[idx].id, time);
            }
        } else {
            // CPU is idle
            printf("Time %d: Idle\n", time);
            time++;
        }
    }

    // Display results
    printf("\nProcess\tArrival\tBurst\tDeadline\tCompletion\tTurnaround\tWaiting\n");

    for (int i = 0; i < n; i++) {
        int turnaround = p[i].completion - p[i].arrival;
        int waiting = turnaround - p[i].burst;

        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].id, p[i].arrival, p[i].burst,
               p[i].deadline, p[i].completion,
               turnaround, waiting);
    }
}

int main() {
    int n;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].id = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst;

        printf("Deadline: ");
        scanf("%d", &p[i].deadline);
    }

    edf(p, n);

    return 0;
}

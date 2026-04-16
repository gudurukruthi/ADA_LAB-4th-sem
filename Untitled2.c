#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

// Structure for process
typedef struct {
    int id;
    int burst;
    int remaining;
    int weight;   // number of tickets
    int executed; // how many times it got CPU
} Process;

void lotteryScheduling(Process p[], int n, int total_time) {
    int total_weight = 0;

    // Calculate total tickets (weights)
    for (int i = 0; i < n; i++) {
        total_weight += p[i].weight;
    }

    srand(time(0));

    printf("\n--- Proportional Scheduling (Lottery) ---\n");

    for (int t = 0; t < total_time; t++) {
        int ticket = rand() % total_weight;
        int sum = 0;

        // Select process based on lottery
        for (int i = 0; i < n; i++) {
            sum += p[i].weight;
            if (ticket < sum) {
                printf("Time %d: Executing P%d\n", t, p[i].id);
                p[i].executed++;
                break;
            }
        }
    }

    // Display execution summary
    printf("\nProcess\tWeight\tTimes Executed\tExpected Share\n");

    for (int i = 0; i < n; i++) {
        float expected = ((float)p[i].weight / total_weight) * total_time;

        printf("P%d\t%d\t%d\t\t%.2f\n",
               p[i].id, p[i].weight,
               p[i].executed, expected);
    }
}

int main() {
    int n, total_time;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input details
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;

        printf("\nProcess %d\n", i + 1);

        printf("Burst Time (optional, for reference): ");
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst;

        printf("Weight (number of tickets): ");
        scanf("%d", &p[i].weight);

        p[i].executed = 0;
    }

    printf("\nEnter total simulation time: ");
    scanf("%d", &total_time);

    lotteryScheduling(p, n, total_time);

    return 0;
}




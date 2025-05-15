/* FCFS CPU Scheduling Algorithm code */
#include <stdio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("Enter the Burst Time for P%d: ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = tat[i - 1];
        tat[i] = bt[i] + wt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t\t%d\t\t%d\t\t%d", i, bt[i], wt[i], tat[i]);
    }

    printf("\n\n");
    printf("Average Waiting Time --> %f\n", wtavg / n);
    printf("Average Turnaround Time --> %f\n", tatavg / n);
    printf("\n");

    return 0;
}
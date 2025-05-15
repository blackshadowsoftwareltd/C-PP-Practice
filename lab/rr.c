/* Round Robin CPU Scheduling Algorithm code */
#include <stdio.h>
#include <conio.h>

int main()
{
    int p[20], bt[20], wt[20], tat[20], rt[20];
    int i, n, quantum, time = 0, count = 0;
    float wtavg = 0, tatavg = 0;

    printf("\n Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        p[i] = i;
        printf(" Enter Burst Time for Process P%d: ", i);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf(" Enter Time Quantum: ");
    scanf("%d", &quantum);
    printf("\n");

    /* Round Robin Scheduling */
    while (count < n)
    {
        for (i = 0; i < n; i++)
        {
            if (rt[i] > 0)
            {
                if (rt[i] > quantum)
                {
                    time += quantum;
                    rt[i] -= quantum;
                }
                else
                {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                    tat[i] = wt[i] + bt[i];
                    wtavg += wt[i];
                    tatavg += tat[i];
                    count++;
                }
            }
        }
    }

    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\n");
    printf("Average Waiting Time --> %f\n", wtavg / n);
    printf("Average Turnaround Time --> %f\n", tatavg / n);
    printf("\n");

    getch();
    return 0;
}
/* SJF CPU Scheduling Algorithm code */
#include <stdio.h>
#include <conio.h>

int main()
{
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("\n Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        p[i] = i;
        printf(" Enter Burst Time for Process P%d: ", i);
        scanf("%d", &bt[i]);
    }

    /* sort processes by burst time */
    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (bt[i] > bt[k])
            {
                temp     = bt[i];
                bt[i]    = bt[k];
                bt[k]    = temp;

                temp     = p[i];
                p[i]     = p[k];
                p[k]     = temp;
            }
        }
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for (i = 1; i < n; i++)
    {
        wt[i]    = tat[i - 1];
        tat[i]   = wt[i] + bt[i];
        wtavg   += wt[i];
        tatavg  += tat[i];
    }

    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    /* © Dept. of Computer Science and Engineering, GUB */

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
/* MVT Memory Management Technique code */
#include <stdio.h>
#include <conio.h>

int main()
{
    int ms, n, mp[10], free_mem, ef;
    int i;

    printf(" Enter the total memory available (in Bytes) -- ");
    scanf("%d", &ms);

    free_mem = ms;

    printf("\n Enter the number of processes -- ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf(" Enter memory required for process %d (in Bytes) -- ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\n Total memory before allocation -- %d", ms);
    printf("\n\n PROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

    for (i = 0; i < n; i++)
    {
        printf("\n %d\t\t%d", i + 1, mp[i]);

        if (mp[i] <= free_mem)
        {
            free_mem -= mp[i];
            printf("\t\tYES\t\t0");
        }
        else
        {
            printf("\t\tNO\t\t---");
        }
    }

    ef = free_mem;
    printf("\n\n Total External Fragmentation is %d", ef);

    getch();
    return 0;
}
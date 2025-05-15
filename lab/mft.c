/* MFT Memory Management Technique code */
#include <stdio.h>
#include <conio.h>

int main()
{
    int ms, bs, nob, ef, n, mp[10], tif = 0;
    int i, p = 0;

    printf(" Enter the total memory available (in Bytes) -- ");
    scanf("%d", &ms);

    printf(" Enter the block size (in Bytes) -- ");
    scanf("%d", &bs);

    nob = ms / bs;
    ef  = ms - nob * bs;

    printf("\n Enter the number of processes -- ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf(" Enter memory required for process %d (in Bytes) -- ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\n No. of Blocks available in memory -- %d", nob);
    printf("\n\n PROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

    for (i = 0; i < n && p < nob; i++)
    {
        printf("\n %d\t\t%d", i + 1, mp[i]);

        if (mp[i] > bs)
        {
            printf("\t\tNO\t\t---");
        }
        else
        {
            printf("\t\tYES\t\t%d", bs - mp[i]);
            tif += (bs - mp[i]);
            p++;
        }
    }

    if (i < n)
        printf("\n\n Memory is Full, Remaining Processes cannot be accomodated");

    printf("\n\n Total Internal Fragmentation is %d", tif);
    printf("\n Total External Fragmentation is %d", ef);

    getch();
    return 0;
}
#include <stdio.h>

int main() {
    int ms, bs, nob, ef, n, mp[10], tif = 0;
    int i, p = 0;

    printf("Enter total memory: ");
    scanf("%d", &ms);
    printf("Enter the block size: ");
    scanf("%d", &bs);

    nob = ms / bs;
    ef = ms - nob * bs;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    for(i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\nNo. of Blocks available in memory: %d", nob);
    printf("\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

    for(i = 0; i < n && p < nob; i++) {
        printf("\n%d\t\t%d", i + 1, mp[i]);
        if(mp[i] > bs)
            printf("\t\tNO\t\t---");
        else {
            printf("\t\tYES\t\t%d", bs - mp[i]);
            tif = tif + bs - mp[i];
            p++;
        }
    }

    if(i < n)
        printf("\n\nMemory is Full, Remaining Processes cannot be accommodated");

    printf("\n\nTotal Internal Fragmentation is %d", tif);
    printf("\nTotal External Fragmentation is %d", ef);

    return 0;
}

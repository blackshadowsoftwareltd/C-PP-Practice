#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int main(void)
{
    int b[MAX], f[MAX], frag[MAX];
    int bf[MAX] = {0}, ff[MAX];
    int nb, nf;
    int i, j, highest, temp;

    printf("Enter the number of blocks (1–%d): ", MAX);
    if (scanf("%d", &nb) != 1 || nb < 1 || nb > MAX)
    {
        fprintf(stderr, "Invalid number of blocks.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the number of files (1–%d): ", MAX);
    if (scanf("%d", &nf) != 1 || nf < 1 || nf > MAX)
    {
        fprintf(stderr, "Invalid number of files.\n");
        return EXIT_FAILURE;
    }

    printf("\nEnter the size of each block:\n");
    for (i = 0; i < nb; i++)
    {
        printf("  Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of each file:\n");
    for (i = 0; i < nf; i++)
    {
        printf("  File   %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    /* Worst‐Fit Allocation */
    for (i = 0; i < nf; i++)
    {
        highest = -1;
        ff[i] = -1;

        for (j = 0; j < nb; j++)
        {
            if (!bf[j] && b[j] >= f[i])
            {
                temp = b[j] - f[i];
                if (temp > highest)
                {
                    highest = temp;
                    ff[i] = j;
                }
            }
        }

        if (ff[i] != -1)
        {
            frag[i] = highest;
            bf[ff[i]] = 1; // mark block as used
        }
        else
        {
            frag[i] = -1; // indicate no fit
        }
    }

    /* Output */
    printf("\nFile_No\tFile_Size\tBlock_No\tBlock_Size\tFragment\n");
    for (i = 0; i < nf; i++)
    {
        if (ff[i] != -1)
        {
            printf("%5d\t%9d\t%8d\t%10d\t%8d\n",
                   i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        }
        else
        {
            printf("%5d\t%9d\t  Not Allocated\n", i + 1, f[i]);
        }
    }

    return EXIT_SUCCESS;
}
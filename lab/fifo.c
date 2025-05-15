#include <stdio.h>

int main() {
    int pageFaultCount = 0, pages[50], memory[20], memoryIndex = 0;
    int numberOfPages, numberOfFrames, i, j, k;

    puts("Enter number of pages:");
    scanf("%d", &numberOfPages);

    puts("Enter the pages:");
    for (i = 0; i < numberOfPages; i++) {
        scanf("%d", &pages[i]);
    }

    puts("Enter number of frames:");
    scanf("%d", &numberOfFrames);
    for (i = 0; i < numberOfFrames; i++) {
        memory[i] = -1;
    }

    puts("The Page Replacement Process is -->");
    for (i = 0; i < numberOfPages; i++) {
        for (j = 0; j < numberOfFrames; j++) {
            if (memory[j] == pages[i]) {
                break;
            }
        }
        if (j == numberOfFrames) {
            memory[memoryIndex] = pages[i];
            memoryIndex++;
            pageFaultCount++;
        }
        for (k = 0; k < numberOfFrames; k++) {
            printf("\t%d", memory[k]);
        }
        if (j == numberOfFrames) {
            printf("\tPage Fault No: %d", pageFaultCount);
        }
        puts("");
        if (memoryIndex == numberOfFrames) {
            memoryIndex = 0;
        }
    }

    printf("The number of Page Faults using FIFO is: %d\n", pageFaultCount);
    return 0;
}
// Best Fit Memory Allocation
#include <stdio.h>

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    
    int nb = 5, np = 4;
    int allocation[10];

    for (int i = 0; i < np; i++)
        allocation[i] = -1;

    for (int i = 0; i < np; i++) {
        int bestIdx = -1;

        for (int j = 0; j < nb; j++) {
            if (blocks[j] >= processes[i]) {
                if (bestIdx == -1 || blocks[j] < blocks[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blocks[bestIdx] -= processes[i];
        }
    }

    printf("Best Fit Allocation:\n");
    for (int i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }

    return 0;
}
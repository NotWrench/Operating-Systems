// FIFO Page Replacement
#include <stdio.h>

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = 7;              // number of pages
    int frames[3];          // 3 frames
    int capacity = 3;

    int front = 0;          // points to oldest page
    int faults = 0;

    // initialize frames
    for (int i = 0; i < capacity; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;

        // check if page already exists
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            // page fault
            frames[front] = pages[i];
            front = (front + 1) % capacity;
            faults++;

            printf("Page %d -> Fault\n", pages[i]);
        } else {
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
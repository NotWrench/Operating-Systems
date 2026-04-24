#include <stdio.h>

int main() {
    int frames, pages, i, j, k, pos, faults = 0;
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[pages], frame[frames], time[frames];

    printf("Enter reference string:\n");
    for(i = 0; i < pages; i++) {
        scanf("%d", &ref[i]);
    }

    // Initialize frames and time
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    int counter = 0;

    for(i = 0; i < pages; i++) {
        int found = 0;

        // Check if page is already in frame
        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                counter++;
                time[j] = counter; // update recent use
                break;
            }
        }

        // If not found, it's a page fault
        if(!found) {
            faults++;

            // Find LRU page
            int min = time[0];
            pos = 0;

            for(j = 1; j < frames; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frame[pos] = ref[i];
            counter++;
            time[pos] = counter;
        }

        // Print frames
        printf("Frames: ");
        for(j = 0; j < frames; j++) {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
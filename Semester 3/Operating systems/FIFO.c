/*
    Develop a C program to simulate page replacement algorithms:
    a) FIFO (First In First Out)
*/
#include <stdio.h>
int main() {
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;
    
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);
    
    printf("\n ENTER THE PAGE NUMBER :\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
        
    printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d", &no);
    
    for (i = 0; i < no; i++)
        frame[i] = -1; // Initialize frames to -1
        
    j = 0; // Initialize frame index
    printf("\tReference String\t Page Frames\n");
    
    for (i = 1; i <= n; i++) {
        printf("%d\t\t", a[i]);
        avail = 0;

        // Check if page is already in frame
        for (k = 0; k < no; k++)
            if (frame[k] == a[i])
                avail = 1;

        // Page fault occurs if page is not in frame
        if (avail == 0) {
            frame[j] = a[i];
            j = (j + 1) % no; // Move to the next frame
            count++;

            // Print current frames
            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
        }
        printf("\n");
    }
    printf("Page Faults: %d\n", count);
    return 0;
}

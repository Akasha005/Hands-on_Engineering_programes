/* Develop a C program to simulate SCAN disk scheduling algorithm. */
#include <stdio.h>

int request[50]; // Array to hold disk requests
int SIZE;        // Size of the disk
int pre;         // Previous request
int head;        // Current head position
int uptrack;     // Number of tracks in the upward direction
int downtrack;   // Number of tracks in the downward direction

struct max {
    int up;    // Upward tracks
    int down;  // Downward tracks
} kate[50];

// Function to calculate the distance between two tracks
int dist(int a, int b) {
    return (a > b) ? a - b : b - a;
}

// Function to sort the request array
void sort(int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (request[j] > request[j + 1]) {
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }
    
    // Splitting the sorted requests into up and down tracks
    int j = 0, i = 0;
    while (request[i] != head) {
        kate[j++].down = request[i++];
    }
    downtrack = j; // Total down tracks
    i++; // Move past the head

    j = 0; // Reset j for upward tracks
    while (i < n) {
        kate[j++].up = request[i++];
    }
    uptrack = j; // Total up tracks
}

// Function to perform the SCAN algorithm
void scan(int n) {
    int i;
    int seekcount = 0; // Total seek count
    printf("SEEK SEQUENCE: ");
    
    sort(n); // Sort the requests

    if (pre < head) {
        // Move upwards first
        for (i = 0; i < uptrack; i++) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].up);
            head = kate[i].up;
        }
        // Move downwards
        for (i = downtrack - 1; i >= 0; i--) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].down);
            head = kate[i].down;
        }
    } else {
        // Move downwards first
        for (i = downtrack - 1; i >= 0; i--) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].down);
            head = kate[i].down;
        }
        // Move upwards
        for (i = 0; i < uptrack; i++) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].up);
            head = kate[i].up;
        }
    }

    printf("%d\nTOTAL DISTANCE: %d\n", head, seekcount);
}

int main() {
    int n, i;
    printf("ENTER THE DISK SIZE:\n");
    scanf("%d", &SIZE);
    
    printf("ENTER THE NO OF REQUEST SEQUENCE:\n");
    scanf("%d", &n);
    
    printf("ENTER THE REQUEST SEQUENCE:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("ENTER THE CURRENT HEAD:\n");
    scanf("%d", &head);

    request[n] = head;         // Include head in requests
    request[n + 1] = SIZE - 1; // Maximum track number
    request[n + 2] = 0;        // Minimum track number

    printf("ENTER THE PRE REQUEST:\n");
    scanf("%d", &pre);

    scan(n + 3); // Call scan function
    return 0;
}

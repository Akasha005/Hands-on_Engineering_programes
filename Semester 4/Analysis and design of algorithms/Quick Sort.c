#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>  // For usleep function

#define maxsize 3000

// Partition function for QuickSort
int partition(int a[], int l, int h) {
    int i = l + 1, j = h, t, pivot = a[l];  // pivot is the first element

    while (1) {
        while (i <= h && a[i] <= pivot)  // Find element greater than pivot
            i++;
        while (a[j] > pivot)  // Find element smaller than pivot
            j--;
        if (i < j) {  // If valid, swap elements
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        } else {  // Final swap of pivot and element at j
            t = a[l];
            a[l] = a[j];
            a[j] = t;
            return j;  // Return partition index
        }
    }
}

// QuickSort function
void quicksort(int a[], int l, int h) {
    int j;
    if (l < h) {
        usleep(500000);  // Sleep for 0.5 seconds
        j = partition(a, l, h);
        quicksort(a, l, j - 1);  // Sort left partition
        quicksort(a, j + 1, h);  // Sort right partition
    }
}

int main() {
    int a[maxsize], i, n;
    double runtime = 0;

    printf("Enter the size: \n");
    scanf("%d", &n);

    srand(1);  // Seed random number generator

    // Generate random numbers
    for (i = 0; i < n; i++)
        a[i] = rand() % 100;

    // Measure the start time
    time_t start = time(NULL);

    // Perform quicksort
    quicksort(a, 0, n - 1);

    // Measure the end time
    time_t end = time(NULL);

    // Calculate the runtime
    runtime = difftime(end, start);

    // Print the sorted array
    printf("The sorted array is:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    // Print the time taken
    printf("Time taken: %f seconds\n", runtime);

    return 0;
}

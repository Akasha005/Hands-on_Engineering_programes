/*
Simulate the FCFS (First-Come, First-Served) CPU scheduling algorithm to find turnaround time and waiting time.
*/

#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;

    printf("Enter total number of processes (maximum 20): ");
    scanf("%d", &n);
    printf("\nEnter Process Burst Time:\n");

    for(i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0; // Waiting time for first process is 0
    for(i = 1; i < n; i++) {
        wt[i] = 0;
        for(j = 0; j < i; j++)
            wt[i] += bt[j]; // Waiting time is sum of burst times of previous processes
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    // Calculating turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    avwt /= n;
    avtat /= n;
    printf("\nAverage Waiting Time: %d", avwt);
    printf("\nAverage Turnaround Time: %d\n", avtat);

    return 0;
}

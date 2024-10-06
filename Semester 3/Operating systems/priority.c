/*
Simulate the Priority Scheduling algorithm to find turnaround time and waiting time.
Processes with a higher priority (lower numerical value) will be executed first.
*/

#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20], pr[20]; // Arrays to hold burst time, priority, waiting time, turnaround time, and process ID
    int i, j, n, total = 0, pos, temp, avg_wt, avg_tat;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);
    
    printf("\nEnter Burst Time and Priority\n");
    for(i = 0; i < n; i++) {
        printf("\nP[%d]\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i + 1; // Process number
    }

    // Sort processes by priority (ascending order)
    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i + 1; j < n; j++) {
            if(pr[j] < pr[pos]) // Higher priority (lower number)
                pos = j;
        }

        // Swap priorities
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
        
        // Swap burst times
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        
        // Swap process numbers
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0; // Waiting time for the first process is 0
    for(i = 1; i < n; i++) {
        wt[i] = 0;
        for(j = 0; j < i; j++)
            wt[i] += bt[j]; // Waiting time is the sum of burst times of previous processes
        total += wt[i];
    }

    avg_wt = total / n; // Average waiting time
    total = 0; // Reset total for turnaround time calculation
    
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst time + Waiting time
        total += tat[i];
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    avg_tat = total / n; // Average turnaround time
    printf("\nAverage Waiting Time = %d", avg_wt);
    printf("\nAverage Turnaround Time = %d\n", avg_tat);

    return 0;
}

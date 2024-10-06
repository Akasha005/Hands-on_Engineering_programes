/*
Simulate the Round Robin CPU scheduling algorithm to find turnaround time and waiting time.
*/

#include <stdio.h>

int main() {
    int count, j, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];

    printf("Enter Total Processes: ");
    scanf("%d", &n);
    remain = n;

    for(count = 0; count < n; count++) {
        printf("Enter Arrival Time and Burst Time for Process Number %d: ", count + 1);
        scanf("%d %d", &at[count], &bt[count]);
        rt[count] = bt[count]; // Remaining time initialized with burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);
    printf("\n\nProcess\t| Turnaround Time | Waiting Time\n\n");

    for(time = 0, count = 0; remain != 0;) {
        if(rt[count] <= time_quantum && rt[count] > 0) {
            time += rt[count]; // Increase current time
            rt[count] = 0; // Process finished
            flag = 1;
        } else if(rt[count] > 0) {
            rt[count] -= time_quantum; // Decrease remaining time
            time += time_quantum; // Increase current time
        }

        // If a process is completed
        if(rt[count] == 0 && flag == 1) {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
            wait_time += time - at[count] - bt[count]; // Calculate waiting time
            turnaround_time += time - at[count]; // Calculate turnaround time
            flag = 0;
        }

        // Loop to the next process
        if(count == n - 1)
            count = 0;
        else if(at[count + 1] <= time)
            count++;
        else
            count = 0; // Reset count if no processes are available
    }

    printf("\nAverage Waiting Time = %f\n", wait_time * 1.0 / n);
    printf("Average Turnaround Time = %f\n", turnaround_time * 1.0 / n);

    return 0;
}

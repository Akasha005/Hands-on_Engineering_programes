#include<stdio.h>
#include<stdlib.h>

int w[10], p[10], v[10][10];

// Function to find the maximum of two numbers
int Max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

// Knapsack dynamic programming algorithm
int knapsack(int n, int c) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (j - w[i] >= 0)
                v[i][j] = Max(v[i-1][j], p[i] + v[i-1][j-w[i]]);
            else
                v[i][j] = v[i-1][j];
        }
    }
    return v[n][c];
}

// Function to print the optimal subset of items
void optimalsubset(int n, int c) {
    int i, j;
    for (i = n, j = c; i >= 1 && j > 0; i--) {
        if (v[i][j] != v[i-1][j]) {
            printf("Item %d\n", i);
            j = j - w[i];
        }
    }
}

int main() {
    int n, c, mp, i, j;
    printf("Enter the number of items: \n");
    scanf("%d", &n);

    printf("Enter the weights of each item: \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter the profit of each item: \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Enter the knapsack capacity: \n");
    scanf("%d", &c);

    // Compute the maximum profit using the knapsack algorithm
    mp = knapsack(n, c);

    printf("Knapsack solution table: \n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++)
            printf("%d\t", v[i][j]);
        printf("\n");
    }

    printf("The maximal value is: %d\n", mp);
    printf("The items in the optimal subset are:\n");
    optimalsubset(n, c);

    return 0;
}

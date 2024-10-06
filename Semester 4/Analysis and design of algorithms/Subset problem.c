#include<stdio.h>

int w[20], d, n, count = 0, x[10], i;

void sumsubsets(int s, int k, int r) {
    x[k] = 1;
    
    if (s + w[k] == d) {
        printf("\nSubset %d ->\t", ++count);
        for (i = 0; i <= k; i++) {
            if (x[i]) 
                printf("%d ", w[i]);
        }
        printf("\n");
    }
    else if (s + w[k] + w[k+1] <= d)
        sumsubsets(s + w[k], k + 1, r - w[k]);

    if ((s + r - w[k] >= d) && (s + w[k+1] <= d)) {
        x[k] = 0;
        sumsubsets(s, k + 1, r - w[k]);
    }
}

int main() {
    int sum = 0;
    
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter the sum: ");
    scanf("%d", &d);

    for (i = 0; i < n; i++)
        x[i] = 0;

    for (i = 0; i < n; i++)
        sum += w[i];

    if (sum < d || w[0] > d) {
        printf("\nNo subset is possible\n");
    } else {
        sumsubsets(0, 0, sum);
    }

    return 0;
}

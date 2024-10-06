#include <stdio.h>
// Structure to represent an item
struct Item {
int weight;
int value;
};
// Function to solve the discrete Knapsack problem using greedy approximation method
void discreteKnapsack(struct Item items[], int n, int capacity) {
// Calculate value-to-weight ratio for each item
float ratios[n];
for (int i = 0; i < n; i++) {
ratios[i] = (float) items[i].value / items[i].weight;
}
// Sort items based on value-to-weight ratio in descending order
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
if (ratios[i] < ratios[j]) {
float tempRatio = ratios[i];
ratios[i] = ratios[j];
ratios[j] = tempRatio;
struct Item tempItem = items[i];
items[i] = items[j];
items[j] = tempItem;
}
}
}
// Fill knapsack
int totalWeight = 0;
float totalValue = 0.0;
printf("Items selected:\n");
for (int i = 0; i < n && totalWeight < capacity; i++) {
if (items[i].weight <= capacity - totalWeight) {
totalWeight += items[i].weight;
totalValue += items[i].value;
printf("Item with weight %d and value %d\n", items[i].weight, items[i].value);
} else {
int remainingWeight = capacity - totalWeight;
totalValue += items[i].value * ((float) remainingWeight / items[i].weight);
printf("Item with weight %d and value %d (fractional part)\n", items[i].weight, items[i].value);
break;
}
}
printf("Total value: %.2f\n", totalValue);
}
int main() {
// Example items
struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
int n = sizeof(items) / sizeof(items[0]);
int capacity = 50;
// Solve discrete Knapsack problem
discreteKnapsack(items, n, capacity);
return 0;
}

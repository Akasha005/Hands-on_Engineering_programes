#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to perform selection sort
void selectionSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int min_idx = i;
for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[min_idx]) {
min_idx = j;
}
}
// Swap the found minimum element with the first element
int temp = arr[i];
arr[i] = arr[min_idx];
arr[min_idx] = temp;
}
}
// Function to generate random integers and store them in a file
void generateRandomNumbersToFile(int n, const char* filename) {
FILE *file = fopen(filename, "w");
if (file == NULL) {
printf("Error opening file.\n");
exit(1);
}
srand(time(NULL)); // Seed for random number generation
for (int i = 0; i < n; i++) {
fprintf(file, "%d\n", rand());
}
fclose(file);
}
// Function to read integers from a file and store them in an array
void readIntegersFromFile(int arr[], int n, const char* filename) {
FILE *file = fopen(filename, "r");
if (file == NULL) {
printf("Error opening file.\n");
exit(1);
}
for (int i = 0; i < n; i++) {
fscanf(file, "%d", &arr[i]);
}
fclose(file);
}
int main() {
FILE *timeFile = fopen("time_vs_n.csv", "w");
if (timeFile == NULL) {
printf("Error opening file.\n");
exit(1);
}
fprintf(timeFile, "n, time_taken_ms\n");
for (int n = 5000; n <= 10000; n += 1000) {
// Generate random numbers and store in a file
generateRandomNumbersToFile(n, "random_numbers.txt");
// Read integers from the file
int arr[n];
readIntegersFromFile(arr, n, "random_numbers.txt");
// Measure the time taken to sort
clock_t start = clock();
selectionSort(arr, n);
clock_t end = clock();
double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
// Record the time taken
fprintf(timeFile, "%d, %lf\n", n, time_taken);
}
fclose(timeFile);
printf("Time taken for sorting recorded in time_vs_n.csv\n");
return 0;
}

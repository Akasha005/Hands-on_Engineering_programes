/*
Design and develop a program in C that uses Hash Function H:K->L as H(K)=K mod m (remainder method) 
and implement hashing technique to map a given key K to the address space L. 
Resolve the collision (if any) using linear probing.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// Structure definition for employee
struct employee {
    int id;
    char name[15];
};

typedef struct employee EMP; 
EMP emp[MAX];
int a[MAX]; // Hash table

// Function to create hash key using remainder method
int create(int num) {
    return num % MAX; // Use MAX as the size for the hash function
}

// Function to get employee details
int getemp(EMP emp[], int key) {
    printf("\nEnter emp id: ");
    scanf("%d", &emp[key].id);
    printf("Enter emp name: ");
    scanf("%s", emp[key].name);
    return key;
}

// Function to display the hash table
void display() {
    int i, ch;
    printf("\n1. Display ALL\n2. Filtered Display");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
        printf("\nThe hash table is:\n");
        printf("\nHTKey\tEmpID\tEmpName");
        for (i = 0; i < MAX; i++) {
            printf("\n%d\t%d\t%s", i, emp[i].id, emp[i].name);
        }
    } else {
        printf("\nThe hash table is:\n");
        printf("\nHTKey\tEmpID\tEmpName");
        for (i = 0; i < MAX; i++) {
            if (a[i] != -1) {
                printf("\n%d\t%d\t%s", i, emp[i].id, emp[i].name);
            }
        }
    }
}

// Function for linear probing to resolve collisions
void linear_prob(int key, int num) {
    int flag = 0, i;
    // Start searching from the next index
    for (i = (key + 1) % MAX; i != key; i = (i + 1) % MAX) {
        if (a[i] == -1) {
            a[i] = getemp(emp, i); // Store employee data in the empty slot
            flag = 1;
            break;
        }
    }
    
    // If no empty slot was found
    if (!flag) {
        printf("Hash table full.\n");
    }
}

void main() {
    int num, key, i;
    int ans = 1;

    // Initialize hash table
    for (i = 0; i < MAX; i++) {
        a[i] = -1; // Mark all slots as empty
    }

    printf("\nCollision handling by linear probing:\n");
    do {
        printf("\nEnter the employee ID (or -1 to exit): ");
        scanf("%d", &num);
        if (num == -1) break; // Exit if user enters -1
        key = create(num); // Generate hash key
        
        if (a[key] == -1) {
            a[key] = getemp(emp, key); // Directly store if the slot is empty
        } else {
            printf("Collision detected at key %d\n", key);
            linear_prob(key, num); // Resolve collision using linear probing
        }
        
        printf("\nDo you wish to continue? (1/0): ");
        scanf("%d", &ans);
    } while (ans);

    display(); // Display the hash table
}

/*
Design, Develop and Implement a Program in C for the following operations on Singly Circular Linked List (SCLL) with header nodes:
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x^2y^2z - 4yz^5 + 3x^3yz + 2xy^5z - 2xyz^3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in POLYSUM(x,y,z).
Support the program with appropriate functions for each of the above operations.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int px;
    int py;
    int pz;
    struct node* next;
};

typedef struct node NODE;

NODE* first = NULL;

// Function to insert a term into the polynomial
void insert(int coef, int px, int py, int pz) {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->coef = coef;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;

    if (first == NULL) {
        temp->next = temp;  // Points to itself, circular
        first = temp;
        return;
    }

    NODE* cur = first;
    // Insert at the end of the circular linked list
    while (cur->next != first) {
        cur = cur->next;
    }
    cur->next = temp;  // Link the last node to the new node
    temp->next = first; // Make it circular
}

// Function to evaluate the polynomial
int evaluate(NODE* poly, int x, int y, int z) {
    int result = 0;
    NODE* cur = poly;
    
    if (cur == NULL) return result;

    do {
        result += cur->coef * (int)pow(x, cur->px) * (int)pow(y, cur->py) * (int)pow(z, cur->pz);
        cur = cur->next;
    } while (cur != poly);

    return result;
}

// Function to display the polynomial
void display(NODE* poly) {
    NODE* cur = poly;

    if (cur == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    do {
        printf("%d*x^%d*y^%d*z^%d ", cur->coef, cur->px, cur->py, cur->pz);
        cur = cur->next;
        if (cur != poly) printf("+ ");
    } while (cur != poly);
    printf("\n");
}

// Function to sum two polynomials
NODE* sumPolynomials(NODE* poly1, NODE* poly2) {
    NODE* result = NULL;
    NODE* cur1 = poly1;
    NODE* cur2 = poly2;

    if (cur1 == NULL) return poly2;
    if (cur2 == NULL) return poly1;

    // Adding terms from both polynomials
    do {
        insert(cur1->coef, cur1->px, cur1->py, cur1->pz);
        cur1 = cur1->next;
    } while (cur1 != poly1);

    do {
        insert(cur2->coef, cur2->px, cur2->py, cur2->pz);
        cur2 = cur2->next;
    } while (cur2 != poly2);

    return first;
}

int main() {
    int x, y, z;
    // Polynomial P(x,y,z) = 6x^2y^2z - 4yz^5 + 3x^3yz + 2xy^5z - 2xyz^3
    insert(6, 2, 2, 1);  // 6x^2y^2z
    insert(-4, 0, 0, 5); // -4yz^5
    insert(3, 3, 1, 0);  // 3x^3yz
    insert(2, 1, 5, 1);  // 2xy^5z
    insert(-2, 1, 1, 3); // -2xyz^3

    printf("Polynomial P(x,y,z): ");
    display(first);

    printf("\nEnter values for x, y, and z to evaluate the polynomial: ");
    scanf("%d %d %d", &x, &y, &z);

    int result = evaluate(first, x, y, z);
    printf("Result of P(%d, %d, %d) = %d\n", x, y, z, result);

    // Summing two polynomials
    NODE* poly1 = first;
    NODE* poly2 = NULL;
    // Adding another polynomial: POLY2
    insert(5, 1, 2, 0); // 5xy^2
    insert(4, 0, 1, 4); // 4y^5z
    poly2 = first;

    // Display second polynomial
    printf("\nSecond Polynomial POLY2(x,y,z): ");
    display(poly2);

    // Sum both polynomials
    printf("\nSummed Polynomial POLYSUM(x,y,z): ");
    sumPolynomials(poly1, poly2);
    display(first);

    return 0;
}

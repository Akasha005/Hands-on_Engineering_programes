/*
Design, Develop and Implement a Program in C for the following Stack Applications:
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^
b. Solving Tower of Hanoi problem with n disks
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// Function to compute result of two operands based on operator
double compute(char symbol, double op1, double op2) {
    switch(symbol) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        case '$':
        case '^':
            return pow(op1, op2);
        default:
            return 0;
    }
}

void evaluatePostfix() {
    double s[20], res, op1, op2;
    int top, i;
    char postfix[20], symbol;
    
    printf("\nEnter the postfix expression:\n");
    scanf("%s", postfix);
    
    top = -1;
    
    for(i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];
        if(isdigit(symbol))
            s[++top] = symbol - '0'; // Convert char to digit
        else {
            // Pop two operands
            op2 = s[top--];
            op1 = s[top--];
            // Compute result based on operator
            res = compute(symbol, op1, op2);
            s[++top] = res; // Push result back to stack
        }
    }
    
    res = s[top--]; // Final result
    printf("\nThe result is: %f\n", res);
}

void towerOfHanoi(int n, int source, int temp, int destination) {
    if(n == 0) return;
    
    towerOfHanoi(n - 1, source, destination, temp);  // Move n-1 discs from source to temp
    printf("\nMove disc %d from %c to %c", n, source, destination);  // Move nth disc to destination
    towerOfHanoi(n - 1, temp, source, destination);  // Move n-1 discs from temp to destination
}

void solveTowerOfHanoi() {
    int n;
    
    printf("\nEnter the number of discs: \n");
    scanf("%d", &n);
    
    towerOfHanoi(n, 'A', 'B', 'C');  // Solve the Tower of Hanoi problem
    printf("\n\nTotal Number of moves are: %d", (int)pow(2, n) - 1);  // 2^n - 1 moves
}

void main() {
    int choice;
    
    do {
        printf("\n\n--- Menu ---");
        printf("\n1. Evaluate Postfix Expression");
        printf("\n2. Solve Tower of Hanoi Problem");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                evaluatePostfix();  // Call postfix evaluation function
                break;
            case 2:
                solveTowerOfHanoi();  // Call Tower of Hanoi function
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please select a valid option.");
        }
    } while(choice != 3);
}

/*
3. Design, Develop and Implement a menu driven Program in C for the following
   operations on STACK of Integers (Array Implementation of Stack with maximum size MAX):
   a. Push an Element on to Stack
   b. Pop an Element from Stack
   c. Demonstrate Overflow and Underflow situations on Stack
   d. Display the status of Stack
   e. Exit

   Support the program with appropriate functions for each of the above operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

int stack[MAX], item;
int ch, top = -1, count = 0;

void push() {
    if (top == (MAX - 1))
        printf("\n\nStack is Overflow");
    else {
        top++;
        stack[top] = item;
    }
}

int pop() {
    int ret;
    if (top == -1)
        printf("\n\nStack is Underflow");
    else {
        ret = stack[top];
        top--;
        printf("\nPopped element is %d", ret);
    }
    return ret;
}

void display() {
    int i;
    printf("\nThe stack contents are:");
    if (top == -1)
        printf("\nStack is Empty");
    else {
        for (i = top; i >= 0; i--)
            printf("\n ------\n| %d |", stack[i]);
        printf("\n");
    }
}

void main() {
    do {
        printf("\n\n----MAIN MENU--- \n");
        printf("\n1. PUSH (Insert) in the Stack");
        printf("\n2. POP (Delete) from the Stack");
        printf("\n3. Exit (End the Execution)");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("\nEnter a element to be pushed: ");
                scanf("%d", &item);
                push();
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\nEND OF EXECUTION");
        }
    } while (ch != 3);
}

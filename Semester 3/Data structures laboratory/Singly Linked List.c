/*
Singly Linked List (SLL) of Integer Data
a. Create a SLL stack of N integers.
b. Display of SLL
c. Linear search.
d. Create a SLL queue of N Students Data.
e. Concatenation of two SLL of integers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX = 4, count;

// Structure definition for student
struct student {
    char usn[10];
    char name[30];
    char branch[5];
    int sem;
    char phno[10];
    struct student *next;
};

typedef struct student NODE;
NODE *head;

// Function to count nodes in the SLL
int countnodes() {
    NODE *p;
    count = 0;
    p = head;
    while (p != NULL) {
        p = p->next;
        count++;
    }
    return count;
}

// Function to create a new node
NODE *getnode() {
    NODE *newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter USN, Name, Branch, Sem, Ph.No\n");
    scanf("%s", newnode->usn);
    scanf("%s", newnode->name);
    scanf("%s", newnode->branch);
    scanf("%d", &(newnode->sem));
    scanf("%s", newnode->phno);
    newnode->next = NULL;
    return newnode;
}

// Function to display the list
NODE *display() {
    NODE *p;
    if (head == NULL)
        printf("\nNo student data\n");
    else {
        p = head;
        printf("\n----STUDENT DATA --- \n");
        printf("\nUSN\tNAME\t\tBRANCH\tSEM\tPh.NO.");
        while (p != NULL) {
            printf("\n%s\t%s\t\t%s\t%d\t%s", p->usn, p->name, p->branch, p->sem, p->phno);
            p = p->next;
        }
        printf("\nThe no. of nodes in list is: %d", countnodes());
    }
    return head;
}

// Function to create the list
NODE *create() {
    NODE *newnode;
    if (head == NULL) {
        newnode = getnode();
        head = newnode;
    } else {
        newnode = getnode();
        newnode->next = head;
        head = newnode;
    }
    return head;
}

// Insert at front for stack functionality
void insert_front() {
    if (countnodes() == MAX)
        printf("\nList is Full / Overflow!!");
    else
        head = create();
}

// Insert at rear for queue functionality
void insert_rear() {
    NODE *p, *newnode;
    p = head;
    if (countnodes() == MAX)
        printf("\nList is Full(QUEUE)!!");
    else {
        if (head == NULL) {
            newnode = getnode();
            head = newnode;
        } else {
            newnode = getnode();
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = newnode;
        }
    }
}

// Insertion menu
void insert() {
    int ch;
    do {
        printf("\n1.Insert at Front(First)\t2.Insert at End(Rear/Last)\t3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert_front(); break;
            case 2: insert_rear(); break;
            case 3: break;
        }
        display();
    } while (ch != 3);
}

// Delete from front
void delete_front() {
    NODE *p;
    if (head == NULL)
        printf("\nList is Empty/Underflow (STACK/QUEUE)");
    else {
        p = head;
        head = head->next;
        free(p);
        printf("\nFront (first) node is deleted");
    }
}

// Delete from rear
void delete_rear() {
    NODE *p, *q;
    p = head;
    if (count == 1) {
        delete_front();
        return;
    }
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    free(p);
    q->next = NULL;
    printf("\nLast (end) entry is deleted");
}

// Deletion menu
void del() {
    int ch;
    do {
        printf("\n1.Delete from Front(First)\t2.Delete from End(Rear/Last)\t3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: delete_front(); break;
            case 2: delete_rear(); break;
            case 3: break;
        }
        display();
    } while (ch != 3);
}

// Stack operations using SLL
NODE *stack() {
    int ch;
    do {
        printf("\nSSL used as Stack...");
        printf("\n 1.Insert at Front (PUSH)\t2.Delete from Front (POP)\t3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert_front(); break;
            case 2: delete_front(); break;
            case 3: break;
        }
        display();
    } while (ch != 3);
}

// Queue operations using SLL
void queue() {
    int ch;
    do {
        printf("\nSSL used as Queue...");
        printf("\n 1.Insert at Rear (INSERT)\t2.Delete from Front (DELETE)\t3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert_rear(); break;
            case 2: delete_front(); break;
            case 3: break;
        }
        display();
    } while (ch != 3);
}

void main() {
    int ch, i, n;
    head = NULL;
    printf("\n*----------Student Database----------*");
    do {
        printf("\n1.Create\t2.Display\t3.Insert\t4.Delete\t5.Stack\t6.Queue\t7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("\nHow many student data you want to create: ");
                scanf("%d", &n);
                for(i = 0; i < n; i++) create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                del();
                break;
            case 5:
                stack();
                break;
            case 6:
                queue();
                break;
            case 7:
                exit(0);
        }
    } while (ch != 7);
}

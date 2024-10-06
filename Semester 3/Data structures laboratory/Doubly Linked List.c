/*
Design, Develop and Implement a menu-driven Program in C for the following operations on Doubly Linked List (DLL) of Professor Data with the fields: 
ID, Name, Branch, Area of specialization.
a. Create a DLL stack of N Professor’s Data.
b. Create a DLL queue of N Professor’s Data.
Display the status of DLL and count the number of nodes in it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX = 4, count; // Max number of nodes allowed in the list

// Structure definition for Professor
struct professor {
    int id;
    char name[30];
    char branch[10];
    char specialization[30];
    struct professor *left; // Pointer to the previous node
    struct professor *right; // Pointer to the next node
};

typedef struct professor NODE;

// Function to count the number of nodes in the DLL
int countnodes(NODE *head) {
    NODE *p;
    count = 0;
    p = head;
    while (p != NULL) {
        p = p->right;
        count++;
    }
    return count;
}

// Function to create a new node for the professor
NODE* getnode() {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->right = newnode->left = NULL;
    printf("\nEnter ID, Name, Branch, Specialization:\n");
    scanf("%d", &newnode->id);
    scanf("%s", newnode->name);
    scanf("%s", newnode->branch);
    scanf("%s", newnode->specialization);
    return newnode;
}

// Function to display the list of professors
NODE* display(NODE *head) {
    NODE *p;
    if (head == NULL) {
        printf("\nNo Professor data\n");
    } else {
        p = head;
        printf("\n----PROFESSOR DATA--- \n");
        printf("\nID\tNAME\tBRANCH\tSPECIALIZATION");
        while (p != NULL) {
            printf("\n%d\t%s\t%s\t%s", p->id, p->name, p->branch, p->specialization);
            p = p->right;
        }
        printf("\nThe number of nodes in the list is: %d", countnodes(head));
    }
    return head;
}

// Function to create a new list or add at the end of the list
NODE* create(NODE *head) {
    NODE *p, *newnode;
    p = head;
    if (head == NULL) {
        newnode = getnode();
        head = newnode;
    } else {
        newnode = getnode();
        while (p->right != NULL) {
            p = p->right;
        }
        p->right = newnode;
        newnode->left = p;
    }
    return head;
}

// Insert at front for stack functionality
NODE* insert_front(NODE *head) {
    NODE *newnode;
    if (countnodes(head) == MAX) {
        printf("\nList is Full!!\n");
    } else {
        newnode = getnode();
        if (head == NULL) {
            head = newnode;
        } else {
            newnode->right = head;
            head->left = newnode;
            head = newnode;
        }
    }
    return head;
}

// Insert at rear for queue functionality
NODE* insert_end(NODE *head) {
    if (countnodes(head) == MAX) {
        printf("\nList is Full!!\n");
    } else {
        head = create(head);
    }
    return head;
}

// Insert menu for adding at the front or end
NODE* insert(NODE *head) {
    int ch;
    do {
        printf("\n1. Insert at Front (First)\t2. Insert at End (Rear/Last)\t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: head = insert_front(head); break;
            case 2: head = insert_end(head); break;
            case 3: break;
            default: printf("\nInvalid choice! Please try again.\n"); break;
        }
        head = display(head);
    } while (ch != 3);
    return head;
}

// Delete from front for queue functionality
NODE* delete_front(NODE *head) {
    NODE *p;
    if (head == NULL) {
        printf("\nList is Empty (QUEUE)\n");
    } else {
        p = head;
        head = head->right;
        if (head != NULL)
            head->left = NULL;
        free(p);
        printf("\nFront (first) node is deleted\n");
    }
    return head;
}

// Delete from rear for stack functionality
NODE* delete_end(NODE *head) {
    NODE *p = head;
    if (head == NULL) {
        printf("\nList is Empty (STACK)\n");
    } else {
        while (p->right != NULL) {
            p = p->right;
        }
        if (p->left != NULL) {
            p->left->right = NULL;
        } else {
            head = NULL;
        }
        free(p);
        printf("\nLast (end) entry is deleted\n");
    }
    return head;
}

// Delete menu for removing from front or end
NODE* del(NODE *head) {
    int ch;
    do {
        printf("\n1. Delete from Front (First)\t2. Delete from End (Rear/Last)\t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: head = delete_front(head); break;
            case 2: head = delete_end(head); break;
            case 3: break;
            default: printf("\nInvalid choice! Please try again.\n"); break;
        }
        head = display(head);
    } while (ch != 3);
    return head;
}

// Queue operations using DLL
NODE* queue(NODE *head) {
    int ch, ch1, ch2;
    do {
        printf("\nDLL used as Double Ended Queue");
        printf("\n1. QUEUE - Insert at Rear & Delete from Front");
        printf("\n2. QUEUE - Insert at Front & Delete from Rear");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                do {
                    printf("\n1. Insert at Rear\t2. Delete from Front\t3. Exit");
                    printf("\nEnter your choice: ");
                    scanf("%d", &ch1);
                    switch (ch1) {
                        case 1: head = insert_end(head); break;
                        case 2: head = delete_front(head); break;
                        case 3: break;
                        default: printf("\nInvalid choice! Please try again.\n"); break;
                    }
                } while (ch1 != 3);
                break;
            case 2:
                do {
                    printf("\n1. Insert at Front\t2. Delete from Rear\t3. Exit");
                    printf("\nEnter your choice: ");
                    scanf("%d", &ch2);
                    switch (ch2) {
                        case 1: head = insert_front(head); break;
                        case 2: head = delete_end(head); break;
                        case 3: break;
                        default: printf("\nInvalid choice! Please try again.\n"); break;
                    }
                } while (ch2 != 3);
                break;
            case 3: break;
            default: printf("\nInvalid choice! Please try again.\n"); break;
        }
    } while (ch != 3);
    head = display(head);
    return head;
}

// Main function with a menu-driven interface
void main() {
    int ch, i, n;
    NODE *head = NULL;
    printf("\n----------Professor Database---------- ");
    do {
        printf("\n1. Create\t2. Display\t3. Insert\t4. Delete\t5. Queue\t6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nHow many professor data do you want to create? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    head = create(head);
                break;
            case 2:
                head = display(head);
                break;
            case 3:
                head = insert(head);
                break;
            case 4:
                head = del(head);
                break;
            case 5:
                head = queue(head);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (ch != 6);
}

/*
Design, Develop and Implement a menu-driven Program in C for the following operations on Binary Search Tree (BST) of Integers:
a. Create a BST of N Integers
b. Traverse the BST in Inorder, Preorder, and Postorder
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Search Tree node
struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST NODE;
NODE *node;

// Function to create the BST
NODE* createtree(NODE *node, int data) {
    if (node == NULL) {
        NODE *temp;
        temp = (NODE*)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < (node->data)) {
        node->left = createtree(node->left, data);
    } else if (data > node->data) {
        node->right = createtree(node->right, data);
    }
    return node;
}

// Function to search for an element in the BST
NODE* search(NODE *node, int data) {
    if (node == NULL) {
        printf("\nElement not found");
    } else if (data < node->data) {
        node->left = search(node->left, data);
    } else if (data > node->data) {
        node->right = search(node->right, data);
    } else {
        printf("\nElement found is: %d", node->data);
    }
    return node;
}

// Inorder traversal (Left, Root, Right)
void inorder(NODE *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(NODE *node) {
    if (node != NULL) {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(NODE *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}

// Function to find the minimum value node in the BST
NODE* findMin(NODE *node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->left)
        return findMin(node->left);
    else
        return node;
}

// Main function with a menu-driven interface
void main() {
    int data, ch, i, n;
    NODE *root = NULL;

    while (1) {
        printf("\n1. Insertion in Binary Search Tree");
        printf("\n2. Search Element in Binary Search Tree");
        printf("\n3. Inorder Traversal");
        printf("\n4. Preorder Traversal");
        printf("\n5. Postorder Traversal");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the number of elements to insert in BST: ");
                scanf("%d", &n);
                printf("\nEnter the values to create BST like (6,9,5,2,8,15,24,14,7):\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = createtree(root, data);
                }
                break;

            case 2:
                printf("\nEnter the element to search: ");
                scanf("%d", &data);
                root = search(root, data);
                break;

            case 3:
                printf("\nInorder Traversal: \n");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("\nPreorder Traversal: \n");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("\nPostorder Traversal: \n");
                postorder(root);
                printf("\n");
                break;

            case 6:
                exit(0);

            default:
                printf("\nWrong option! Please try again.");
                break;
        }
    }
}

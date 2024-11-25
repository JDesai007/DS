#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the threaded binary tree
struct Node {
    int data;
    struct Node *left, *right;
    int rightThread;  // 1 if the right pointer is a thread, 0 if it is a child
};

// Function to insert a new node in the threaded binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        // Creating a new node if root is NULL
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        newNode->rightThread = 0;
        return newNode;
    }
    
    struct Node* parent = NULL;
    struct Node* current = root;
    
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            if (current->left == NULL) {
                break;
            } else {
                current = current->left;
            }
        } else if (data > current->data) {
            if (current->right == NULL || current->rightThread == 1) {
                break;
            } else {
                current = current->right;
            }
        }
    }
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->rightThread = 0;

    // Inserting the new node in the tree
    if (data < parent->data) {
        parent->left = newNode;
        newNode->right = parent;
    } else if (data > parent->data) {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->right = newNode;
        parent->rightThread = 0;
    }

    return root;
}

// Function to perform inorder traversal using threaded binary tree
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    // Traverse to the leftmost node
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }

    // Now, traverse using the right threads
    while (current != NULL) {
        printf("%d ", current->data);

        // If there is a right thread, follow it
        if (current->rightThread == 1) {
            current = current->right;
        } else {
            current = current->right;
            while (current != NULL && current->left != NULL) {
                current = current->left;
            }
        }
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

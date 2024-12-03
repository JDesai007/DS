#include <stdio.h>
#include <stdlib.h>

// Enum for thread type
enum PointerType { CHILD, THREAD };

// Structure for a threaded binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    enum PointerType leftThread;
    enum PointerType rightThread;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = THREAD;
    newNode->rightThread = THREAD;
    return newNode;
}

// Function to insert a new node into the threaded binary tree
struct TreeNode* insert(struct TreeNode* root, int value) {
    struct TreeNode* parent = NULL;
    struct TreeNode* current = root;

    // Find the correct position for the new node
    while (current != NULL) {
        parent = current;

        if (value < current->data) {
            if (current->leftThread == CHILD) {
                current = current->left;
            } else {
                break;
            }
        } else if (value > current->data) {
            if (current->rightThread == CHILD) {
                current = current->right;
            } else {
                break;
            }
        } else {
            printf("Value %d already exists in the tree. Duplicate values are not allowed.\n", value);
            return root;
        }
    }

    // Create the new node
    struct TreeNode* newNode = createNode(value);

    if (parent == NULL) {
        root = newNode; // First node becomes the root
    } else if (value < parent->data) {
        // Insert as the left child
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = CHILD;
        parent->left = newNode;
    } else {
        // Insert as the right child
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rightThread = CHILD;
        parent->right = newNode;
    }

    printf("Inserted %d into the tree.\n", value);
    return root;
}

// Function to perform inorder traversal of the threaded binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }

    struct TreeNode* current = root;

    // Find the leftmost node
    while (current->leftThread == CHILD) {
        current = current->left;
    }

    printf("Inorder Traversal: ");
    while (current != NULL) {
        printf("%d ", current->data);

        // If right pointer is a thread, follow it
        if (current->rightThread == THREAD) {
            current = current->right;
        } else {
            // Otherwise, move to the leftmost node in the right subtree
            current = current->right;
            while (current != NULL && current->leftThread == CHILD) {
                current = current->left;
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    int choice, value;

    while (1) {
        printf("\nThreaded Binary Tree Operations:\n");
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
                inorderTraversal(root);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

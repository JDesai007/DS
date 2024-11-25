#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Iterative insert in the binary tree (Level Order insertion)
void iterativeInsert(struct Node** root, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Use a queue to find the first available spot for insertion
    struct Node* queue[100];  // Static array as queue for simplicity
    int front = 0, rear = 0;

    // Enqueue the root
    queue[rear++] = *root;

    while (front != rear) {
        struct Node* current = queue[front++];

        // Check if left child is available for insertion
        if (current->left == NULL) {
            current->left = newNode;
            return;
        } else {
            queue[rear++] = current->left;
        }

        // Check if right child is available for insertion
        if (current->right == NULL) {
            current->right = newNode;
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}

// Function to display the binary tree iteratively (Level Order Traversal)
void iterativeDisplay(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct Node* queue[100];  // Static array as queue for simplicity
    int front = 0, rear = 0;

    // Enqueue the root
    queue[rear++] = root;

    printf("Level Order Traversal: ");
    while (front != rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        // Enqueue left child
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        // Enqueue right child
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

// Function to find the inorder successor (used for deleting nodes with two children)
struct Node* inorderSuccessor(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Iterative function to delete a node containing given data
void deleteNode(struct Node** root, int data) {
    if (*root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct Node* parent = NULL;
    struct Node* current = *root;

    // Find the node to delete
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If node is not found
    if (current == NULL) {
        printf("Node with value %d not found.\n", data);
        return;
    }

    // Case 1: Node has no children (leaf node)
    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) {
            *root = NULL; // Tree had only one node
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(current);
    }
    // Case 2: Node has one child
    else if (current->left == NULL || current->right == NULL) {
        struct Node* child = (current->left != NULL) ? current->left : current->right;

        if (parent == NULL) {
            *root = child;
        } else if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(current);
    }
    // Case 3: Node has two children
    else {
        struct Node* successor = inorderSuccessor(current->right);
        int successorData = successor->data;
        deleteNode(root, successor->data); // Recursively delete the successor
        current->data = successorData; // Replace current node's data with successor's data
    }
    printf("Deleted node with value %d.\n", data);
}

int main() {
    struct Node* root = NULL;  // Initialize an empty binary tree
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Iterative Insert\n");
        printf("2. Iterative Display (Level Order)\n");
        printf("3. Delete Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                iterativeInsert(&root, value);
                break;
            case 2:
                iterativeDisplay(root);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&root, value);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value); // Create a new node if the tree is empty
    }

    if (value < root->data) {
        root->left = insert(root->left, value); // Insert into the left subtree
    } else if (value > root->data) {
        root->right = insert(root->right, value); // Insert into the right subtree
    } else {
        printf("Value %d already exists in the tree. Duplicate values are not allowed.\n", value);
    }
    return root;
}

// Function for preorder traversal
void preorder(struct TreeNode* root) {
    if (root == NULL) return;

    printf("%d ", root->data); // Visit the root
    preorder(root->left);      // Traverse the left subtree
    preorder(root->right);     // Traverse the right subtree
}

// Function for inorder traversal
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);       // Traverse the left subtree
    printf("%d ", root->data); // Visit the root
    inorder(root->right);      // Traverse the right subtree
}

// Function for postorder traversal
void postorder(struct TreeNode* root) {
    if (root == NULL) return;

    postorder(root->left);     // Traverse the left subtree
    postorder(root->right);    // Traverse the right subtree
    printf("%d ", root->data); // Visit the root
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

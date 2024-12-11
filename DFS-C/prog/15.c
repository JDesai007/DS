#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue for level-order traversal
struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to initialize a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a tree node
void enqueue(struct Queue* queue, struct TreeNode* treeNode) {
    struct QueueNode* newQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newQueueNode;
    } else {
        queue->rear->next = newQueueNode;
        queue->rear = newQueueNode;
    }
}

// Function to dequeue a tree node
struct TreeNode* dequeue(struct Queue* queue) {
    if (queue->front == NULL) return NULL;

    struct QueueNode* temp = queue->front;
    struct TreeNode* treeNode = temp->treeNode;
    queue->front = queue->front->next;

    if (queue->front == NULL) queue->rear = NULL;

    free(temp);
    return treeNode;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to insert a node iteratively into the binary tree
void iterativeInsert(struct TreeNode** root, int value) {
    struct TreeNode* newNode = createTreeNode(value);

    if (*root == NULL) {
        *root = newNode;
        printf("Inserted %d as the root node.\n", value);
        return;
    }

    struct Queue* queue = createQueue();
    enqueue(queue, *root);

    while (!isQueueEmpty(queue)) {
        struct TreeNode* current = dequeue(queue);

        if (current->left == NULL) {
            current->left = newNode;
            printf("Inserted %d to the left of %d.\n", value, current->data);
            break;
        } else {
            enqueue(queue, current->left);
        }

        if (current->right == NULL) {
            current->right = newNode;
            printf("Inserted %d to the right of %d.\n", value, current->data);
            break;
        } else {
            enqueue(queue, current->right);
        }
    }
}

// Function to display the tree iteratively (level-order traversal)
void iterativeDisplay(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    printf("Tree (Level-order): ");
    while (!isQueueEmpty(queue)) {
        struct TreeNode* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left) enqueue(queue, current->left);
        if (current->right) enqueue(queue, current->right);
    }
    printf("\n");
}

// Function to delete the deepest node in the tree
void deleteDeepestNode(struct TreeNode* root, struct TreeNode* target) {
    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isQueueEmpty(queue)) {
        struct TreeNode* current = dequeue(queue);

        if (current == target) {
            current = NULL;
            free(target);
            return;
        }

        if (current->left) {
            if (current->left == target) {
                current->left = NULL;
                free(target);
                return;
            } else {
                enqueue(queue, current->left);
            }
        }

        if (current->right) {
            if (current->right == target) {
                current->right = NULL;
                free(target);
                return;
            } else {
                enqueue(queue, current->right);
            }
        }
    }
}

// Function to delete a node with the given value
void deleteNode(struct TreeNode** root, int value) {
    if (*root == NULL) {
        printf("The tree is empty. Cannot delete %d.\n", value);
        return;
    }

    struct Queue* queue = createQueue();
    enqueue(queue, *root);

    struct TreeNode* targetNode = NULL;
    struct TreeNode* current = NULL;

    while (!isQueueEmpty(queue)) {
        current = dequeue(queue);

        if (current->data == value) {
            targetNode = current;
        }

        if (current->left) enqueue(queue, current->left);
        if (current->right) enqueue(queue, current->right);
    }

    if (targetNode != NULL) {
        int deepestValue = current->data;
        deleteDeepestNode(*root, current);
        targetNode->data = deepestValue;
        printf("Deleted node containing %d.\n", value);
    } else {
        printf("Value %d not found in the tree.\n", value);
    }
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Tree Operations:\n");
        printf("1. Iterative Insert\n");
        printf("2. Iterative Display\n");
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

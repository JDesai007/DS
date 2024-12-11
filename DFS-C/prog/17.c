#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct Node {
    int data;
    struct Node* right;  // Points to the next element in the same row
    struct Node* down;   // Points to the next element in the same column
};

// Structure to represent a matrix
struct Matrix {
    struct Node** rowHead;  // Points to an array of row linked lists
    struct Node** colHead;  // Points to an array of column linked lists
    int rows;  // Number of rows
    int cols;  // Number of columns
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}

// Function to create a matrix with given rows and columns
struct Matrix* createMatrix(int rows, int cols) {
    struct Matrix* matrix = (struct Matrix*)malloc(sizeof(struct Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    
    // Allocate memory for row and column heads
    matrix->rowHead = (struct Node**)malloc(rows * sizeof(struct Node*));
    matrix->colHead = (struct Node**)malloc(cols * sizeof(struct Node*));
    
    // Initialize row and column heads to NULL
    for (int i = 0; i < rows; i++) {
        matrix->rowHead[i] = NULL;
    }
    for (int i = 0; i < cols; i++) {
        matrix->colHead[i] = NULL;
    }
    
    return matrix;
}

// Function to create the matrix and input elements from user
void create(struct Matrix* matrix) {
    int value;
    for (int i = 0; i < matrix->rows; i++) {
        struct Node* prevRowNode = NULL;
        for (int j = 0; j < matrix->cols; j++) {
            printf("Enter value for matrix[%d][%d]: ", i, j);
            scanf("%d", &value);
            
            // Create a new node for the current matrix element
            struct Node* newNode = createNode(value);
            
            // Insert in the current row
            if (prevRowNode != NULL) {
                prevRowNode->right = newNode;  // Link the node in the current row
            } else {
                matrix->rowHead[i] = newNode;  // First node in the row
            }
            
            // Insert in the current column
            if (matrix->colHead[j] == NULL) {
                matrix->colHead[j] = newNode;  // First node in the column
            } else {
                struct Node* prevColNode = matrix->colHead[j];
                while (prevColNode->down != NULL) {
                    prevColNode = prevColNode->down;
                }
                prevColNode->down = newNode;  // Link the node in the column
            }
            
            prevRowNode = newNode;  // Move to the next node in the row
        }
    }
}

// Function to display the matrix
void display(struct Matrix* matrix) {
    printf("Matrix:\n");
    for (int i = 0; i < matrix->rows; i++) {
        struct Node* currentNode = matrix->rowHead[i];
        for (int j = 0; j < matrix->cols; j++) {
            if (currentNode != NULL) {
                printf("%d ", currentNode->data);
                currentNode = currentNode->right;
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct Matrix* matrix = NULL;
    int rows, cols, choice;

    while (1) {
        printf("\nMatrix Operations (Multilinked Structure):\n");
        printf("1. Create Matrix\n");
        printf("2. Display Matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of rows: ");
                scanf("%d", &rows);
                printf("Enter the number of columns: ");
                scanf("%d", &cols);
                matrix = createMatrix(rows, cols);
                create(matrix);
                break;
            case 2:
                if (matrix == NULL) {
                    printf("Matrix is not created yet.\n");
                } else {
                    display(matrix);
                }
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

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list (matrix element)
struct Node {
    int data;
    struct Node* right;  // Pointer to the next element in the same row
    struct Node* down;   // Pointer to the next element in the same column
};

// Structure to represent the matrix
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

// Function for matrix addition
struct Matrix* addMatrices(struct Matrix* matrix1, struct Matrix* matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrix dimensions must match for addition.\n");
        return NULL;
    }

    struct Matrix* result = createMatrix(matrix1->rows, matrix1->cols);

    for (int i = 0; i < matrix1->rows; i++) {
        struct Node* currentNode1 = matrix1->rowHead[i];
        struct Node* currentNode2 = matrix2->rowHead[i];
        struct Node* prevRowNode = NULL;

        for (int j = 0; j < matrix1->cols; j++) {
            int sum = currentNode1->data + currentNode2->data;

            struct Node* newNode = createNode(sum);
            
            if (prevRowNode != NULL) {
                prevRowNode->right = newNode;
            } else {
                result->rowHead[i] = newNode;
            }

            if (result->colHead[j] == NULL) {
                result->colHead[j] = newNode;
            } else {
                struct Node* prevColNode = result->colHead[j];
                while (prevColNode->down != NULL) {
                    prevColNode = prevColNode->down;
                }
                prevColNode->down = newNode;
            }

            prevRowNode = newNode;

            currentNode1 = currentNode1->right;
            currentNode2 = currentNode2->right;
        }
    }

    return result;
}

// Function for matrix multiplication
struct Matrix* multiplyMatrices(struct Matrix* matrix1, struct Matrix* matrix2) {
    if (matrix1->cols != matrix2->rows) {
        printf("Matrix dimensions are not compatible for multiplication.\n");
        return NULL;
    }

    struct Matrix* result = createMatrix(matrix1->rows, matrix2->cols);

    for (int i = 0; i < matrix1->rows; i++) {
        struct Node* currentNode1 = matrix1->rowHead[i];

        for (int j = 0; j < matrix2->cols; j++) {
            struct Node* currentNode2 = matrix2->colHead[j];
            int sum = 0;

            for (int k = 0; k < matrix1->cols; k++) {
                sum += currentNode1->data * currentNode2->data;
                currentNode1 = currentNode1->right;
                currentNode2 = currentNode2->down;
            }

            struct Node* newNode = createNode(sum);
            struct Node* prevRowNode = result->rowHead[i];
            struct Node* prevColNode = result->colHead[j];

            if (prevRowNode != NULL) {
                prevRowNode->right = newNode;
            } else {
                result->rowHead[i] = newNode;
            }

            if (prevColNode != NULL) {
                prevColNode->down = newNode;
            } else {
                result->colHead[j] = newNode;
            }
        }
    }

    return result;
}

// Main function
int main() {
    struct Matrix* matrix1 = NULL;
    struct Matrix* matrix2 = NULL;
    struct Matrix* result = NULL;
    int rows, cols, choice;

    while (1) {
        printf("\nMatrix Operations (Multilinked Structure):\n");
        printf("1. Create Matrix 1\n");
        printf("2. Create Matrix 2\n");
        printf("3. Display Matrix 1\n");
        printf("4. Display Matrix 2\n");
        printf("5. Matrix Addition\n");
        printf("6. Matrix Multiplication\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of rows for Matrix 1: ");
                scanf("%d", &rows);
                printf("Enter the number of columns for Matrix 1: ");
                scanf("%d", &cols);
                matrix1 = createMatrix(rows, cols);
                create(matrix1);
                break;
            case 2:
                printf("Enter the number of rows for Matrix 2: ");
                scanf("%d", &rows);
                printf("Enter the number of columns for Matrix 2: ");
                scanf("%d", &cols);
                matrix2 = createMatrix(rows, cols);
                create(matrix2);
                break;
            case 3:
                display(matrix1);
                break;
            case 4:
                display(matrix2);
                break;
            case 5:
                result = addMatrices(matrix1, matrix2);
                if (result != NULL) {
                    display(result);
                }
                break;
            case 6:
                result = multiplyMatrices(matrix1, matrix2);
                if (result != NULL) {
                    display(result);
                }
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

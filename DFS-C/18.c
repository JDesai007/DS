#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Node (an element in a matrix)
struct Node {
    int value;
    struct Node* next;
};

// Structure to represent a Row (linked list of nodes)
struct Row {
    struct Node* head;
    struct Row* next;
};

// Structure to represent a Matrix (linked list of rows)
struct Matrix {
    struct Row* head;
    int rows;
    int cols;
};

// Function to create a matrix with input from the user
struct Matrix* createMatrix(int rows, int cols) {
    struct Matrix* mat = (struct Matrix*)malloc(sizeof(struct Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->head = NULL;

    struct Row* currentRow = NULL;
    for (int i = 0; i < rows; i++) {
        struct Row* newRow = (struct Row*)malloc(sizeof(struct Row));
        newRow->head = NULL;
        newRow->next = NULL;

        if (mat->head == NULL) {
            mat->head = newRow;
        } else {
            currentRow->next = newRow;
        }
        currentRow = newRow;

        struct Node* currentNode = NULL;
        for (int j = 0; j < cols; j++) {
            int value;
            printf("Enter element at [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &value);
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->value = value;
            newNode->next = NULL;
            
            if (currentRow->head == NULL) {
                currentRow->head = newNode;
            } else {
                currentNode->next = newNode;
            }
            currentNode = newNode;
        }
    }

    return mat;
}

// Function to display a matrix
void displayMatrix(struct Matrix* mat) {
    struct Row* currentRow = mat->head;
    while (currentRow != NULL) {
        struct Node* currentNode = currentRow->head;
        while (currentNode != NULL) {
            printf("%d ", currentNode->value);
            currentNode = currentNode->next;
        }
        printf("\n");
        currentRow = currentRow->next;
    }
}

// Function to add two matrices
struct Matrix* addMatrices(struct Matrix* mat1, struct Matrix* mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        printf("Matrix dimensions do not match for addition!\n");
        return NULL;
    }

    struct Matrix* result = (struct Matrix*)malloc(sizeof(struct Matrix));
    result->rows = mat1->rows;
    result->cols = mat1->cols;
    result->head = NULL;

    struct Row* row1 = mat1->head;
    struct Row* row2 = mat2->head;
    struct Row* resultRow = NULL;

    while (row1 != NULL) {
        struct Row* newRow = (struct Row*)malloc(sizeof(struct Row));
        newRow->head = NULL;
        newRow->next = NULL;
        if (result->head == NULL) {
            result->head = newRow;
        } else {
            resultRow->next = newRow;
        }
        resultRow = newRow;

        struct Node* node1 = row1->head;
        struct Node* node2 = row2->head;
        struct Node* resultNode = NULL;

        while (node1 != NULL) {
            int sum = node1->value + node2->value;
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->value = sum;
            newNode->next = NULL;

            if (newRow->head == NULL) {
                newRow->head = newNode;
            } else {
                resultNode->next = newNode;
            }
            resultNode = newNode;

            node1 = node1->next;
            node2 = node2->next;
        }

        row1 = row1->next;
        row2 = row2->next;
    }

    return result;
}

// Function to multiply two matrices
struct Matrix* multiplyMatrices(struct Matrix* mat1, struct Matrix* mat2) {
    if (mat1->cols != mat2->rows) {
        printf("Matrix dimensions do not match for multiplication!\n");
        return NULL;
    }

    struct Matrix* result = (struct Matrix*)malloc(sizeof(struct Matrix));
    result->rows = mat1->rows;
    result->cols = mat2->cols;
    result->head = NULL;

    struct Row* row1 = mat1->head;
    struct Row* resultRow = NULL;

    for (int i = 0; i < mat1->rows; i++) {
        struct Row* newRow = (struct Row*)malloc(sizeof(struct Row));
        newRow->head = NULL;
        newRow->next = NULL;
        if (result->head == NULL) {
            result->head = newRow;
        } else {
            resultRow->next = newRow;
        }
        resultRow = newRow;

        struct Node* resultNode = NULL;

        for (int j = 0; j < mat2->cols; j++) {
            int sum = 0;
            struct Row* row2 = mat2->head;
            struct Node* node1 = row1->head;

            while (row2 != NULL) {
                struct Node* node2 = row2->head;
                for (int k = 0; k < j; k++) {
                    node2 = node2->next;
                }

                if (node2 != NULL) {
                    sum += node1->value * node2->value;
                }

                row2 = row2->next;
                node1 = node1->next;
            }

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->value = sum;
            newNode->next = NULL;

            if (newRow->head == NULL) {
                newRow->head = newNode;
            } else {
                resultNode->next = newNode;
            }
            resultNode = newNode;
        }

        row1 = row1->next;
    }

    return result;
}

int main() {
    int choice, rows, cols;

    // Create first matrix
    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &rows);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &cols);
    struct Matrix* mat1 = createMatrix(rows, cols);

    // Create second matrix
    printf("Enter number of rows for matrix 2: ");
    scanf("%d", &rows);
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &cols);
    struct Matrix* mat2 = createMatrix(rows, cols);

    do {
        printf("\nMenu:\n");
        printf("1. Display Matrix 1\n");
        printf("2. Display Matrix 2\n");
        printf("3. Add Matrices\n");
        printf("4. Multiply Matrices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMatrix 1:\n");
                displayMatrix(mat1);
                break;
            case 2:
                printf("\nMatrix 2:\n");
                displayMatrix(mat2);
                break;
            case 3:
                printf("\nMatrix Addition Result:\n");
                struct Matrix* addResult = addMatrices(mat1, mat2);
                if (addResult != NULL) {
                    displayMatrix(addResult);
                }
                break;
            case 4:
                printf("\nMatrix Multiplication Result:\n");
                struct Matrix* mulResult = multiplyMatrices(mat1, mat2);
                if (mulResult != NULL) {
                    displayMatrix(mulResult);
                }
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the matrix (each cell in the matrix is a node)
struct Node {
    int data;
    struct Node *right, *down;
};

// Structure to represent the matrix (rows are linked in the 'down' direction, columns in the 'right' direction)
struct Matrix {
    struct Node *head;
};

// Function to create a matrix (rows and columns are linked)
void createMatrix(struct Matrix* mat, int rows, int cols) {
    mat->head = NULL;
    struct Node* rowHead = NULL;
    struct Node* prevRow = NULL;

    // Create rows
    for (int i = 0; i < rows; i++) {
        struct Node* prev = NULL;
        rowHead = NULL;
        
        // Create columns for each row
        for (int j = 0; j < cols; j++) {
            int value;
            printf("Enter value for element (%d, %d): ", i + 1, j + 1);
            scanf("%d", &value);
            
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->right = NULL;
            newNode->down = NULL;
            
            if (rowHead == NULL) {
                rowHead = newNode;  // First element in the row
            } else {
                prev->right = newNode;  // Link the previous node to the current node
            }
            prev = newNode;  // Move to the current node for the next iteration
        }

        // Link the rows vertically (down pointers)
        if (mat->head == NULL) {
            mat->head = rowHead;  // First row
        } else {
            prevRow->down = rowHead;  // Link the previous row's down pointer to the current row's head
        }
        prevRow = rowHead;  // Move to the current row for the next iteration
    }
}

// Function to display the matrix
void displayMatrix(struct Matrix* mat) {
    if (mat->head == NULL) {
        printf("Matrix is empty.\n");
        return;
    }

    struct Node* row = mat->head;
    while (row != NULL) {
        struct Node* col = row;
        while (col != NULL) {
            printf("%d ", col->data);
            col = col->right;
        }
        printf("\n");
        row = row->down;
    }
}

int main() {
    struct Matrix mat;
    int choice, rows, cols;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Matrix\n");
        printf("2. Display Matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of rows: ");
                scanf("%d", &rows);
                printf("Enter number of columns: ");
                scanf("%d", &cols);
                createMatrix(&mat, rows, cols);
                break;
            case 2:
                printf("Matrix:\n");
                displayMatrix(&mat);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Definition of a doubly circular linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Head pointer for the list
struct Node* head = NULL;

// Function to insert a node at the end of the doubly circular linked list
void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode;

    if (!head) {
        head = newNode;
    } else {
        struct Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

    printf("Inserted: %d\n", data);
}

// Function to delete a node by value
void deleteNode(int data) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        if (current->data == data) {
            if (current == head && current->next == head) {
                free(current);
                head = NULL;
                printf("Deleted the last node %d. List is now empty.\n", data);
                return;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == head) {
                    head = current->next; // Update head if the first node is deleted
                }
                free(current);
                printf("Deleted: %d\n", data);
                return;
            }
        }
        current = current->next;
    } while (current != head);

    printf("Node with value %d not found.\n", data);
}

// Function to display the list (forward traversal)
void displayList() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("List (Forward): ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to display the list (backward traversal)
void displayReverse() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head->prev;
    printf("List (Backward): ");
    do {
        printf("%d ", current->data);
        current = current->prev;
    } while (current != head->prev);
    printf("\n");
}

// Main function to test the doubly circular linked list
int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert at End\n2. Delete Node\n3. Display List\n4. Display List in Reverse\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                displayList();  // Display list in forward direction
                break;
            case 4:
                displayReverse();  // Display list in reverse direction
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) { // If the list is empty
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d into the list.\n", value);
}

// Function to delete a node by value
void delete(struct Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head node itself holds the value to be deleted
    if (temp != NULL && temp->data == value) {
        *head = temp->next; // Change head
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    // Search for the value to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value not found in the list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}

// Function to modify a node's value
void modify(struct Node* head, int oldValue, int newValue) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            printf("Modified value %d to %d.\n", oldValue, newValue);
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list.\n", oldValue);
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Singly Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value, oldValue, newValue;

    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(&head, value);
                break;
            case 3:
                printf("Enter value to modify: ");
                scanf("%d", &oldValue);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                modify(head, oldValue, newValue);
                break;
            case 4:
                display(head);
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

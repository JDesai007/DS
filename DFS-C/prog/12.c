#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) { 
        newNode->next = newNode; 
        *head = newNode;
    } else {
        struct Node* temp = *head;
        
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Insert the new node at the end and update links
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("Inserted %d into the circular list.\n", value);
}

// Function to delete a node by value
void delete(struct Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head node itself holds the value
    if (temp->data == value) {
        // Find the last node to update its next pointer
        while (temp->next != *head) {
            temp = temp->next;
        }
        if (temp == *head) { // Only one node in the list
            free(*head);
            *head = NULL;
        } else {
            temp->next = (*head)->next;
            free(*head);
            *head = temp->next;
        }
        printf("Deleted %d from the circular list.\n", value);
        return;
    }

    // Search for the value in the list
    struct Node* current = *head;
    do {
        prev = current;
        current = current->next;
        if (current->data == value) {
            prev->next = current->next;
            free(current);
            printf("Deleted %d from the circular list.\n", value);
            return;
        }
    } while (current != *head);

    printf("Value %d not found in the list.\n", value);
}

// Function to modify a node's value
void modify(struct Node* head, int oldValue, int newValue) {
    if (head == NULL) {
        printf("The list is empty. Cannot modify.\n");
        return;
    }

    struct Node* temp = head;
    do {
        if (temp->data == oldValue) {
            temp->data = newValue;
            printf("Modified value %d to %d.\n", oldValue, newValue);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Value %d not found in the list.\n", oldValue);
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value, oldValue, newValue;

    while (1) {
        printf("\nSingly Circular Linked List Operations:\n");
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

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;  // Initialize head of the list

// Function to insert a new node at the end of the circular linked list
void insert(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* temp = head;
    new_node->data = data;
    new_node->next = head;

    if (head == NULL) {
        head = new_node;
        new_node->next = head;  // Point to itself
    } else {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to delete the first occurrence of a node with the given data
void delete(int data) {
    Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == data) {
        // Special case: head node needs to be deleted
        if (temp->next == head) {
            free(temp);
            head = NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
        return;
    }

    while (temp != NULL && temp->next != head) {
        if (temp->next->data == data) {
            Node* to_delete = temp->next;
            temp->next = to_delete->next;
            free(to_delete);
            return;
        }
        temp = temp->next;
    }

    printf("Element %d not found.\n", data);
}

// Function to modify the first occurrence of a node with old data to new data
void modify(int old_data, int new_data) {
    Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        if (temp->data == old_data) {
            temp->data = new_data;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Element %d not found.\n", old_data);
}

// Function to display the circular linked list
void display() {
    Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to display the menu and handle user input
void menu() {
    int choice, data, old_data, new_data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the integer to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the integer to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                printf("Enter the integer to modify: ");
                scanf("%d", &old_data);
                printf("Enter the new integer: ");
                scanf("%d", &new_data);
                modify(old_data, new_data);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}

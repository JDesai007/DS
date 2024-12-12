#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to insert a new node at the end of the list
void insert(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = head;
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to delete the first occurrence of a node with given data
void delete(int data) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to modify the first occurrence of a node with given old data to new data
void modify(int old_data, int new_data) {
    Node* temp = head;

    while (temp != NULL && temp->data != old_data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", old_data);
        return;
    }

    temp->data = new_data;
}

// Function to display the linked list
void display() {
    Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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

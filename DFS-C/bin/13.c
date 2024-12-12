#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Define the structure for a node in the doubly circular linked list
typedef struct Node {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;  // Initialize head of the list

// Function to create a new node
Node* createNode(int id, const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    strncpy(new_node->name, name, MAX_NAME_LENGTH - 1);
    new_node->name[MAX_NAME_LENGTH - 1] = '\0';
    new_node->next = new_node;
    new_node->prev = new_node;
    return new_node;
}

// Function to insert a new node at the end of the doubly circular linked list
void insert(int id, const char* name) {
    Node* new_node = createNode(id, name);
    
    if (head == NULL) {
        head = new_node;
    } else {
        Node* last = head->prev;
        last->next = new_node;
        new_node->prev = last;
        new_node->next = head;
        head->prev = new_node;
    }
}

// Function to delete the first occurrence of a node with the given ID
void delete(int id) {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        if (temp->id == id) {
            if (temp->next == temp) {
                // Only one node in the list
                free(temp);
                head = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head) {
                    head = temp->next;
                }
                free(temp);
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Student with ID %d not found.\n", id);
}

// Function to modify the information of the first occurrence of a node with the given ID
void modify(int id, const char* new_name) {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        if (temp->id == id) {
            strncpy(temp->name, new_name, MAX_NAME_LENGTH - 1);
            temp->name[MAX_NAME_LENGTH - 1] = '\0';
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Student with ID %d not found.\n", id);
}

// Function to display the doubly circular linked list
void display() {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    } while (temp != head);
}

// Function to display the menu and handle user input
void menu() {
    int choice, id;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &id);
                getchar();  // Consume the newline character
                printf("Enter student name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';  // Remove the newline character
                insert(id, name);
                break;
            case 2:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                delete(id);
                break;
            case 3:
                printf("Enter student ID to modify: ");
                scanf("%d", &id);
                getchar();  // Consume the newline character
                printf("Enter new student name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';  // Remove the newline character
                modify(id, name);
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

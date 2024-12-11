#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student node in the doubly circular linked list
struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
    struct Student* prev;
};

// Function to create a new node
struct Student* createNode(int roll, char* name, float marks) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->marks = marks;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// Function to insert a new student at the end
void insert(struct Student** head, int roll, char* name, float marks) {
    struct Student* newNode = createNode(roll, name, marks);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Student* last = (*head)->prev;

        // Insert at the end
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }

    printf("Student with roll number %d inserted.\n", roll);
}

// Function to delete a student by roll number
void delete(struct Student** head, int roll) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    struct Student* current = *head;

    // Search for the student by roll number
    do {
        if (current->roll == roll) {
            if (current->next == current && current->prev == current) {
                // Only one node in the list
                *head = NULL;
            } else {
                // Update links
                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == *head) {
                    *head = current->next; // Update head if needed
                }
            }
            free(current);
            printf("Student with roll number %d deleted.\n", roll);
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Student with roll number %d not found.\n", roll);
}

// Function to modify student information
void modify(struct Student* head, int roll, char* newName, float newMarks) {
    if (head == NULL) {
        printf("The list is empty. Cannot modify.\n");
        return;
    }

    struct Student* current = head;

    // Search for the student by roll number
    do {
        if (current->roll == roll) {
            strcpy(current->name, newName);
            current->marks = newMarks;
            printf("Student with roll number %d modified.\n", roll);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Student with roll number %d not found.\n", roll);
}

// Function to display the list
void display(struct Student* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Student* current = head;
    printf("\nStudent Information:\n");
    printf("Roll\tName\t\tMarks\n");

    do {
        printf("%d\t%-15s%.2f\n", current->roll, current->name, current->marks);
        current = current->next;
    } while (current != head);
}

// Main function
int main() {
    struct Student* head = NULL;
    int choice, roll;
    char name[50];
    float marks;

    while (1) {
        printf("\nDoubly Circular Linked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                printf("Enter name: ");
                scanf(" %[^\n]s", name); // Read a string with spaces
                printf("Enter marks: ");
                scanf("%f", &marks);
                insert(&head, roll, name, marks);
                break;
            case 2:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                delete(&head, roll);
                break;
            case 3:
                printf("Enter roll number to modify: ");
                scanf("%d", &roll);
                printf("Enter new name: ");
                scanf(" %[^\n]s", name);
                printf("Enter new marks: ");
                scanf("%f", &marks);
                modify(head, roll, name, marks);
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

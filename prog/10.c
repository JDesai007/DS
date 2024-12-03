#include <stdio.h>
#include <stdlib.h>

// Structure for a priority queue node
struct Node {
    int data;          // Value of the element
    int priority;      // Priority of the element
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* newNode(int data, int priority) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Function to enqueue an element into the priority queue
void enqueue(struct Node** head, int data, int priority) {
    struct Node* start = *head;
    struct Node* temp = newNode(data, priority);

    // If the queue is empty or the new node has the highest priority
    if (*head == NULL || (*head)->priority > priority) {
        temp->next = *head;
        *head = temp;
    } else {
        // Traverse the queue and find the correct position
        while (start->next != NULL && start->next->priority <= priority) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to dequeue an element with the highest priority
void dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }
    struct Node* temp = *head;
    printf("Dequeued Element: Data=%d, Priority=%d\n", temp->data, temp->priority);
    *head = (*head)->next;
    free(temp);
}

// Function to display the priority queue
void display(struct Node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Priority Queue:\n");
    while (head != NULL) {
        printf("Data=%d, Priority=%d\n", head->data, head->priority);
        head = head->next;
    }
}

// Main function
void main() {
    struct Node* pq = NULL;
    int choice, data, priority;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue Element\n");
        printf("2. Dequeue Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&pq, data, priority);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(pq);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Define the size of the circular queue

// Circular Queue structure
struct CircularQueue {
    int items[SIZE];
    int front, rear;
};

// Initialize the circular queue
void initializeQueue(struct CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->rear + 1) % SIZE == queue->front;
}

// Function to insert an element into the circular queue
void insert(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(queue)) { // If the queue is empty
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % SIZE;
    queue->items[queue->rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

// Function to delete an element from the circular queue
void delete(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    int value = queue->items[queue->front];
    if (queue->front == queue->rear) { // If the queue has only one element
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % SIZE;
    }
    printf("Deleted %d from the queue.\n", value);
}

// Function to modify an element in the queue
void modify(struct CircularQueue* queue, int oldValue, int newValue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot modify.\n");
        return;
    }

    int i = queue->front;
    int found = 0;
    while (1) {
        if (queue->items[i] == oldValue) {
            queue->items[i] = newValue;
            printf("Modified value %d to %d.\n", oldValue, newValue);
            found = 1;
            break;
        }
        if (i == queue->rear) break;
        i = (i + 1) % SIZE;
    }

    if (!found) {
        printf("Value %d not found in the queue.\n", oldValue);
    }
}

// Function to display the elements of the queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->items[i]);
        if (i == queue->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    int choice, value, oldValue, newValue;

    while (1) {
        printf("\nCircular Queue Operations:\n");
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
                insert(&queue, value);
                break;
            case 2:
                delete(&queue);
                break;
            case 3:
                printf("Enter value to modify: ");
                scanf("%d", &oldValue);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                modify(&queue, oldValue, newValue);
                break;
            case 4:
                display(&queue);
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

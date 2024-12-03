#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a process
struct Process {
    int pid;                 // Process ID
    char name[50];           // Process Name
    struct Process* next;    // Pointer to the next process in the queue
};

// Structure to represent the process queue
struct Queue {
    struct Process* front;   // Front of the queue
    struct Process* rear;    // Rear of the queue
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to enqueue a process
void enqueue(struct Queue* queue, int pid, char* name) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    newProcess->pid = pid;
    strcpy(newProcess->name, name);
    newProcess->next = NULL;

    if (queue->rear == NULL) { // If the queue is empty
        queue->front = queue->rear = newProcess;
        return;
    }
    queue->rear->next = newProcess;
    queue->rear = newProcess;
}

// Function to dequeue a process
void dequeue(struct Queue* queue) {
    if (queue->front == NULL) { // If the queue is empty
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }
    struct Process* temp = queue->front;
    printf("Dequeued Process: PID=%d, Name=%s\n", temp->pid, temp->name);
    queue->front = queue->front->next;
    if (queue->front == NULL) { // If the queue becomes empty
        queue->rear = NULL;
    }
    free(temp);
}

// Function to display the process queue
void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) { // If the queue is empty
        printf("Queue is empty.\n");
        return;
    }
    struct Process* current = queue->front;
    printf("Process Queue:\n");
    while (current != NULL) {
        printf("PID=%d, Name=%s\n", current->pid, current->name);
        current = current->next;
    }
}

// Main function
int main() {
    struct Queue processQueue;
    initializeQueue(&processQueue);

    int choice, pid;
    char name[50];

    while (1) {
        printf("\nProcess Queue Operations:\n");
        printf("1. Enqueue Process\n");
        printf("2. Dequeue Process\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Process ID: ");
                scanf("%d", &pid);
                printf("Enter Process Name: ");
                scanf("%s", name);
                enqueue(&processQueue, pid, name);
                break;
            case 2:
                dequeue(&processQueue);
                break;
            case 3:
                displayQueue(&processQueue);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

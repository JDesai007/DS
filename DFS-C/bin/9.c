#include <stdio.h>
#include <stdlib.h>

#define MAX 10  

typedef struct {
    int process[MAX];  
    int front;         
    int rear;          
} ProcessQueue;

void initQueue(ProcessQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(ProcessQueue *q) {
    return q->front == -1;
}

int isFull(ProcessQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}
void enqueue(ProcessQueue *q, int processID) {
    if (isFull(q)) {
        printf("Queue is full. Cannot add more processes.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->process[q->rear] = processID;
    printf("Process %d added to the queue.\n", processID);
}

int dequeue(ProcessQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No process to remove.\n");
        return -1;
    }
    int processID = q->process[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Process %d removed from the queue.\n", processID);
    return processID;
}

void displayQueue(ProcessQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Processes in the queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->process[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    ProcessQueue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    displayQueue(&q);

    dequeue(&q);
    dequeue(&q);

    displayQueue(&q);

    enqueue(&q, 4);
    enqueue(&q, 5);

    displayQueue(&q);

    return 0;
}

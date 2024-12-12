#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertSorted() {
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (!head || head->data >= data) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("Node inserted.\n");
}

void deleteNode() {
    int data;
    printf("Enter data to delete: ");
    scanf("%d", &data);

    struct Node *temp = head, *prev = NULL;
    while (temp && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        if (prev) prev->next = temp->next;
        else head = temp->next;
        free(temp);
        printf("Node deleted.\n");
    } else {
        printf("Node not found.\n");
    }
}

void updateNode() {
    int oldData, newData;
    printf("Enter data to update: ");
    scanf("%d", &oldData);

    struct Node* current = head;
    while (current && current->data != oldData) current = current->next;

    if (current) {
        printf("Enter new data: ");
        scanf("%d", &newData);
        current->data = newData;
        insertSorted();  
        printf("Node updated.\n");
    } else {
        printf("Node not found.\n");
    }
}

void displayList() {
    struct Node* current = head;
    if (!current) {
        printf("List is empty.\n");
        return;
    }
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void main() {
    int choice;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Update\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertSorted(); break;
            case 2: deleteNode(); break;
            case 3: updateNode(); break;
            case 4: displayList(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}

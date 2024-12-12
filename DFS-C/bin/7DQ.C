#include <stdio.h>
#include<conio.h>
#define SIZE 5

int queue1[SIZE], queue2[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
int i = 0;

void insertQueue1(int value);
void insertQueue2(int value);
void deleteQueue1();
void deleteQueue2();
void modifyQueue1(int position, int value);
void modifyQueue2(int position, int value);
void displayQueue1();
void displayQueue2();

int main() {
    int choice, value, position, queueChoice;

    do{
	clrscr();
	printf("\n\t    --------------------------");
	printf("\n\t\tDouble Queue Program...");
	printf("\n\n\t\tPress 1: Insert_front \n\t\tPress 2: Insert_rear \n\t\tPress 3: Delete_front  \n\t\tPress 4: Delete_rear \n\t\tPress 5: Modify_front \n\t\tPress 6: Modify_rear \n\t\tPress 7: Display_front \n\t\tPress 8: Dispaly_rear \n\t\tPress 0: End");
	printf("\n\t    --------------------------");
	printf("\n\nEnter your choice as per above List: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter the value to be inserted in Queue 1: ");
		scanf("%d", &value);
		insertQueue1(value);
		break;
	    case 2:
		printf("Enter the value to be inserted in Queue 2: ");
		scanf("%d", &value);
		insertQueue2(value);
		break;
	    case 3:
		deleteQueue1();
		break;
	    case 4:
		deleteQueue2();
		break;
	    case 5:
		printf("Enter the position to modify in Queue 1 (1-based index): ");
		scanf("%d", &position);
		printf("Enter the new value: ");
		scanf("%d", &value);
		modifyQueue1(position, value);
		break;
	    case 6:
		printf("Enter the position to modify in Queue 2 (1-based index): ");
		scanf("%d", &position);
		printf("Enter the new value: ");
		scanf("%d", &value);
		modifyQueue2(position, value);
		break;
	    case 7:
		displayQueue1();
		getch();
		break;
	    case 8:
		displayQueue2();
		getch();
		break;
	    case 0:exit(0);
		getch();
	    default:
		printf("Invalid choice! Please try again.\n");
	}
    } while(1);
}

void insertQueue1(int value) {
    if (rear1 == SIZE - 1) {
        printf("Queue 1 is Full\n");
        return;
    } else if (front1 == -1) {
        front1 = rear1 = 0;
    } else {
        rear1++;
    }
    queue1[rear1] = value;
    printf("Inserted %d in Queue 1\n", value);
}

void insertQueue2(int value) {
    if (rear2 == SIZE - 1) {
        printf("Queue 2 is Full\n");
        return;
    } else if (front2 == -1) {
        front2 = rear2 = 0;
    } else {
        rear2++;
    }
    queue2[rear2] = value;
    printf("Inserted %d in Queue 2\n", value);
}

void deleteQueue1() {
    if (front1 == -1) {
        printf("Queue 1 is Empty\n");
        return;
    }

    printf("Deleted %d from Queue 1\n", queue1[front1]);

    if (front1 == rear1) {
        front1 = rear1 = -1;
    } else {
        front1++;
    }
}

void deleteQueue2() {
    if (front2 == -1) {
        printf("Queue 2 is Empty\n");
        return;
    }

    printf("Deleted %d from Queue 2\n", queue2[front2]);

    if (front2 == rear2) {
        front2 = rear2 = -1;
    } else {
        front2++;
    }
}

void modifyQueue1(int position, int value) {
	int index;
    if (front1 == -1) {
        printf("Queue 1 is Empty\n");
        return;
    }

    index = front1 + position - 1;
    if (index > rear1 || index < front1) {
        printf("Invalid position! Please try again.\n");
    } else {
        queue1[index] = value;
	printf("Modified at index [%d] in Queue 1 to %d\n", position, value);
    }
}

void modifyQueue2(int position, int value) {
    int index;
    if (front2 == -1) {
        printf("Queue 2 is Empty\n");
        return;
    }

    index = front2 + position - 1;
    if (index > rear2 || index < front2) {
        printf("Invalid position! Please try again.\n");
    } else {
        queue2[index] = value;
	printf("Modified at index[%d] in Queue 2 to %d\n", position, value);
    }
}

void displayQueue1() {
    if (front1 == -1) {
        printf("Queue 1 is Empty\n");
        return;
    }

    printf("Queue 1 elements are: \n");
    for (i = front1; i <= rear1; i++) {
	printf("%d->", queue1[i]);
    }
    printf("\n");
}

void displayQueue2() {
    if (front2 == -1) {
	printf("Queue 2 is Empty\n");
	return;
    }

    printf("Queue 2 elements are: \n");
    for (i = front2; i <= rear2; i++) {
	printf("%d->", queue2[i]);
    }
    printf("\n");
}


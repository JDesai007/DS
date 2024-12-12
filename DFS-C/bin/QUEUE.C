#include<stdio.h>
#include<conio.h>

#define max 3

int q[max],rear=-1,front=-1;

void insert()
{
	int x;
	if(rear==max-1)
	{
		printf("\nQueue is full..");
	}
	else
	{

		printf("\n Enter Data: ");
		scanf("%d",&x);
		rear++;
		q[rear]=x;
	}
}
void pop()
{
	if(front==-1 && rear==-1)
	{
		printf("queue is Empty");
	}
	else if(front== rear)
	{

		front=-1;
		rear=-1;
		printf("\ndata is Deleted..");
	}
	else
	{
		front++;
		printf("\nData is deleted..");
	}
}
void display()
{
	int i;
	if(rear > front)
	{
		printf("\nQueue is empty");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d",q[i]);
		}
	}
}

void main()
{
	int choice;
	do
	{
		clrscr();
		printf("\nPress 1:Insert");
		printf("\nPress 2:Delete");
		printf("\nPress 3:Display");
		printf("\nPress 0:Exit");

		printf("\nEnter your choice: ");
		scanf("%d",&choice);


		switch(choice)
		{
			case 1:insert();
			getch();
			break;

			case 2:pop();
			getch();
			break;

			case 3:display();
			getch();
			break;

			case 0:exit(0);
			break;

			default:
			printf("Please enter valid choice");
		}
	}while(1);
}
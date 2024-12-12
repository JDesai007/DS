#include<stdio.h>
#include<conio.h>

#define size 5

int front=-1,rear=-1;
int q[size];

void push()
{
	int d;
	if(rear==size-1)
	{
		printf("\nQueue is full..");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		printf("Enter data q[%d]: ",rear);
		scanf("%d",&d);
		q[rear]=d;

	}
	else
	{
		rear=rear+1;
		printf("Enter data q[%d]: ",rear);
		scanf("%d",&d);
		q[rear]=d;


	}


}

void pop()
{
	if(front==-1 && rear==-1)
	{
		printf("\nQueue is Empty");
	}
	else if(front==rear)
	{
		printf("\n%d is deleted successfully...",q[front]);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("\n%d is deleted successfully...",q[front]);
		front++;

	}

}

void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("\nQueue is Empty..");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d->",q[i]);
		}
	}
}

void modify()
{
	int d,i,no;
	if(front==-1 && rear==-1)
	{
		printf("\nQueue is Empty..");
	}
	else
	{
		printf("\nEnter data to Modify: ");
		scanf("%d",&no);

		for(i=front;i<=rear && q[i]!=no;i++)
		{
			;
		}
		if(i<=rear)
		{
			printf("\nEnter new data: ");
			scanf("%d",&d);

			if(q[i]==no)
			{
				q[i]=d;
				printf("\nData is Updated at[%d] index...",i);
				return;
			}
			printf("\nData is Updated at[%d]..",i);
			return;
		}
		printf("Data is not Found..");
	}
}

void main()
{
	int choice;

	do
	{
		clrscr();
		printf("\n\t    --------------------------");
		printf("\n\t\tQueue Program...");
		printf("\n\n\t\tPress 1: Push  \n\t\tPress 2: POP \n\t\tPress 3: Display  \n\t\tPress 4: Modify  \n\t\tPress 0: End");
		printf("\n\t    --------------------------");
		printf("\n\nEnter your choice as per above List: ");
		scanf("%d", &choice);

		  switch(choice)
		  {
			case 1:push();
				getch();
				break;

			case 2:pop();
				getch();
				break;

			case 3:display();
				getch();
				break;

			case 4:modify();
				getch();
				break;

			case 0:exit(0);
				break;
		  }

	}while(1);
}
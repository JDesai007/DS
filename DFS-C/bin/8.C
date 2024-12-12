#include<stdio.h>
#include<conio.h>
#include<math.h>
#define max 5
int front=-1,rear=-1;
int cque[max];

void push()
{
	int d;
	if((rear+1)%max==front)
	{
		printf("Queue is full");
	}
	else
	{
		printf("Enter data:");
		scanf("%d",&d);

		if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
			cque[rear]=d;
		}
		else
		{
			if(rear==max-1 && front!=0)
			{
				rear=0;
				cque[rear]=d;
			}
			else
			{
				rear=rear+1;
				cque[rear]=d;
			}
		}
	}
}
void pop()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty");
	}
	else
	{
		if(front==rear)
		{
			printf("%d is deleted..",cque[front]);
			front=-1;
			rear=-1;
		}
		else
		{
			if(front==max-1 && rear>=0)
			{
				printf("%d is deleted..",cque[front]);
				front=0;
			}
			else
			{
				printf("%d is deleted..",cque[front]);
				front=front+1;
			}
		}
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty");
	}
	else
	{
		if(front<rear || front==rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d->",cque[i]);
			}
		}
		else
		{
			for(i=front;i<=max-1;i++)
			{
				printf("%d->",cque[i]);
			}
			for(i=0;i<=rear;i++)
			{
				printf("%d->",cque[i]);
			}
		}
	}
}
void modify()
{
	int no,d,i;
	if(rear==-1)
	{
		printf("\nQueue is Empty..");
	}
	else
	{
		printf("\nEnter data to Modify: ");
		scanf("%d",&no);
		if(front < rear || front==rear)
		{
		for(i=front;i<=rear && cque[i]!=no;i++)
		{
			;
		}
		if(i<=rear)
		{
			printf("\nEnter new data: ");
			scanf("%d",&d);

			if(cque[i]==no)
			{
				cque[i]=d;
				printf("\nData is Updated at[%d] index...",i);
				return;
			}
			printf("\nData is Updated at[%d]..",i);
			return;
		}
		}
		else
		{
			for(i=front;i<=max-1;i++)
			{

			printf("\nEnter new data: ");
			scanf("%d",&d);

			if(cque[i]==no)
			{
				cque[i]=d;
				printf("\nData is Updated at[%d] index...",i);
				return;
			}
			for(i=0;i<=rear;i++)
			{
				if(cque[i]==no)
				{
					cque[i]=d;
					printf("\nData is Updated at[%d] index...",i);
					return;
				}
			}
			printf("\nData is Updated at[%d]..",i);
			return;
			}
		}
		printf("Not found");

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
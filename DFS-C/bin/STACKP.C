#include<stdio.h>
#include<conio.h>

struct stack
{
  int data;
  struct stack *s;
}*start=NULL,*end=NULL,*temp=NULL;

void push()
{
	temp=(struct stack*)malloc(sizeof(struct stack));
	printf("Enter data: ");
	scanf("%d",&temp->data);
	temp->s=NULL;

	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->s=end;
	}
	end=temp;
}

void pop()
{
	if(end==NULL)
	{
		printf("List is Empty");
	}
	else if(end==start)
	{
		printf("%d is Deleted...",start->data);
		end=NULL;
		start=NULL;
		temp=NULL;
		free(end);
		free(start);

	}
	else
	{
		temp=end;
		printf("%d is Deleted..",temp->data);
		end=end->s;
		free(temp);
	}
}

void display()
{
	if(start==NULL)
	{
		printf("List is Empty");
	}
	else
	{
		for(temp=end;temp!=NULL;temp=temp->s)
		{
			printf("%d->",temp->data);
		}
	}
}

void main()
{
	int choice;
	do
	{

	clrscr();
	printf("Stack program...");

	printf("\n Press 1:Push");
	printf("\n Press 2:pop");
	printf("\n Press 3:Display");
	printf("\n Press 0:Exit");

	printf("\n Enter your choice: ");
	scanf("%d",&choice);

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

		case 0:exit(0);
			break;

		default: printf("\n please enter valid choice");
	}
	}while(1);
}
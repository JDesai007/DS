#include<stdio.h>
#include<conio.h>

#define SIZE 10

int top = -1, stack[SIZE];
void push();
void pop();
void peep();
void update();
void show();

void main()
{
    int choice;

    do
    {
	clrscr();
	printf("\n\t    --------------------------");
	printf("\n\t\tStack Program...");
	printf("\n\n\t\tPress 1: Push \n\t\tPress 2: Pop \n\t\tPress 3: Show  \n\t\tPress 4: peep \n\t\tPress 5: Update \n\t\tPress 0: End");
	printf("\n\t    --------------------------");
	printf("\n\nEnter your choice as per above List: ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
		    push();
		    getch();
		    break;

		case 2:
		    pop();
		    getch();
		    break;

		case 3:
		    show();
		    getch();
		    break;

		case 4:
		    peep();
		    getch();
		    break;

		case 5:
		    update();
		    getch();
		    break;

		case 0:
		    exit(0);
		    break;

	default:
	    printf("\nplease Enter valid choice..");
	}
    } while(1);


}

void push()
{
    int x;

    if (top == SIZE - 1)
    {
	printf("\nStack is full..");
    }
    else
    {
	printf("\nEnter element on Stack: ");
	scanf("%d", &x);
	top = top + 1;
	stack[top] = x;
    }
    printf("\n");
}

void pop()
{
    if (top == -1)
    {
	printf("\nStack is Empty");
    }
    else
    {
	printf("\n%d is Deleted..", stack[top]);
	top = top - 1;
    }
    printf("\n");
}

void show()
{
int i;
    if (top == -1)
    {
	printf("\nStack is Empty");
    }
    else
    {
	printf("\nElements present in the stack: \n");
	for (i = top; i >= 0; i--)
	    printf("%d->", stack[i]);
    }
    printf("\n");
}
void peep()
{
	int no,i;
	if(top==-1)
	{
		printf("Stack is Empty..");
	}
	else
	{
		printf("Enter data you want to search: ");
		scanf("%d",&no);

		for(i=top; i>=-1 && stack[i]!=no; i--)
		{
		      ;
		}
		if(i!=-1)
		{
			if(stack[i]==no)
			{
				printf("%d is Found at[%d] index",no,i);
				return;
			}
			printf("%d is Not Found...",no);
			return;
		}

		printf("%d is Not Found...",no);


	}
}
void update()
{
	int no,i,d;
	if(top==-1)
	{
		printf("Stack is Empty..");
	}
	else
	{
		printf("Enter data you want to search: ");
		scanf("%d",&no);

		for(i=top; i>=-1 && stack[i]!=no; i--)
		{
		      ;
		}
		if(i!=-1)
		{
			printf("Enter the new data: ");
			scanf("%d",&d);

			if(stack[i]==no)
			{

				stack[i]=d;
				printf("Data updated successfully at[%d]",i);
				return;
			}
			printf("%d is Not Found",no);
			return;
		}

		printf("%d is Not Found",no);


	}
}
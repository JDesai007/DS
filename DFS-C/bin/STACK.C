#include<stdio.h>
#include<conio.h>

#define SIZE 10

int top = -1, stack[SIZE];
void push();
void pop();
void peep();
void show();

void main()
{
    int choice;
      
    do
    {
	clrscr();
	printf("\nStack Prrogram..");
	printf("\n1.Push \n2.Pop \n3.Show  \n4.peep \n0.End");
	printf("\n\nEnter your choice: ");
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
	case 0:
	    exit(0);

	default:
	    printf("\nInvalid choice..");
	}
    } while(1);


}

void push()
{
    int x;

    if (top == SIZE - 1)
    {
	printf("\nOverflow!!");
    }
    else
    {
	printf("\nEnter element on STACK: ");
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
	printf("\nList is Empty");
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
				printf("Found");
				return;
			}
			printf("Not Found");
			return;
		}

		printf("Not Found");


	}
}
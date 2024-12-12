#include<stdio.h>
#include<conio.h>
#define max 5

int data=-1;
int stack[max];

void push()
{
	int x;
	if(data==max-1)
	{
		printf("Stack is full..");
	}
	else
	{
		printf("Enter data:");
		scanf("%d",&x);
		data=data+1;
		stack[data]=x;

	}
}

void pop()
{
	if(data==-1)
	{
		printf("Stack Is Empty");
	}
	else
	{
		printf("%d is Deleted...",stack[data]);
		data=data-1;
	}
}
void show()
{
	int i;
	if(data==-1)
	{
	    printf("Stack is empty");
	}
	else
	{
	for(i=data;i>=0;i--)
	{
		printf("%d->",stack[i]);
	}
	}
}
void peep()
{
int d,i;
	if(data==-1)
	{
		printf("Stack is empty..");
	}
	else
	{
		printf("Enter data you want to search:");
		scanf("%d",&d);
		for(i=data;i>=-1 && stack[i]!=d;i--)
		{
			 ;
		}
		if(i!=-1)
		{
			if(stack[i]==d)
			{
				printf("%d is found at [%d] index",d,i);
			}
			else
			{
				printf("%d is not found",d);
			}
		}
		else
		{
			printf("%d is not found",d);
		}
	}
}

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

	       //	case 5:
	     //	    update();
	     //	    getch();
	   //	    break;

		case 0:
		    exit(0);
		    break;

	default:
	    printf("\nplease Enter valid choice..");
	}
    } while(1);


}
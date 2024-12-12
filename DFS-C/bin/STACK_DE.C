
#include<stdio.h>
#include<conio.h>
#define size 5

int top=-1;
int arr[size];
void push()
{
int data;
  if(top==size-1)
  {
	printf("Stack is full...");
  }
  else
  {
	printf("Enter data:");
	scanf("%d",&data);
	top=top+1;
	arr[top]=data;
  }

}
void pop()
{
	if(top==-1)
	{
		printf("Stack is empty..");
	}
	else
	{
		printf("%d is deleted..",arr[top]);
		top=top-1;

	}
}
void display()
{
   int i=0;
   if(top==-1)
   {
	printf("Stack is empty");
   }
   else
   {
   for(i=top;i>=0;i--)
   {
	printf("%d->",arr[i]);
   }
   }
}

void peep()
{
	int no,i;
	if(top==-1)
	{
		printf("Stack is empty..");
	}
	else
	{
		printf("Enter the number you want to search:");
		scanf("%d",&no);

		for(i=top;i>=-1 && arr[i]!=no;i--)
		{
			;
		}
		if(i!=-1)
		{
			if(arr[i]==no)
			{
				printf("%d is found at[%d] index",no,i);
				return;
			}
			printf("%d is not found..",no);
			return;
		}
		printf("%d is not found..",no);
	}
}
void update()
{
	int no,i,d;
	if(top==-1)
	{
		printf("Stack is empty.. ");
	}
	else
	{
		printf("Enter data to update:");
		scanf("%d",&no);

		for(i=top;i>=-1 && arr[i]!=no;i--)
		{
			;
		}

		if(i!=-1)
		{
			printf("Enter new data:");
			scanf("%d",&d);
			if(arr[i]==no)
			{
				arr[i]=d;
				printf("Data updated...");
				return;

			}
			printf("Data not found");
		}
		printf("Data not found..");
		return;
	}
}
void main()
{
	int choice;
	do
	{
		clrscr();
		printf("Stack program");
		printf("\n1.Push \n2.Pop \n3.Display \n4.Peep \n5.Update \n0.Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:push();
				getch();
				break;
			case 2: pop();
				getch();
				break;
			case 3: display();
				getch();
				break;
			case 4:peep();
				getch();
				break;
			case 5:update();
				getch();
				break;

			case 0:exit(0);
				break;

			default :
				printf("Please enter valid choice:");
				getch();
				break;


		}
	}while(1);
}
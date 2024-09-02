#include<stdio.h>
#include<conio.h>

#define max 5

int top1=-1,top2=max;
int arr[max];

void push_first()
{
	int data;
	if(top1<top2-1)
	{
		top1++;
		printf("Enter data: ");
		scanf("%d",&data);
		arr[top1]=data;

	}
	else
	{
		printf("Stack is full");
	}
}
void push_last()
{
	int data;
	if(top1 < top2 -1)
	{
		top2--;
		printf("Enter data: ");
		scanf("%d",&data);
		arr[top2]=data;

	}
	else
	{
		printf("Stack is full");
	}
}
void pop_first()
{
	if(top1==-1)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("%d is deleted..",arr[top1]);
		arr[top1--];
	}

}
void pop_last()
{
	if(top2==max)
	{
		printf("Stack is empty..");
	}
	else

	{
		printf("%d is deleted..",arr[top2]);
		arr[top2++];
	}
}
void show_first()
{
	int i;
	if(top1==-1)
	{
		printf("Stack is empty");
	}
	else
	{
		for(i=top1;i>=0;i--)
		{
			printf("%d->",arr[i]);
		}
	}
}
void show_last()
{
	int i;
	if(top2==max)
	{
		printf("Stack is empty");
	}
	else
	{
	      for(i=top2;i<max;i++)
	      {
			printf("%d->",arr[i]);
	      }
	}
}
void peep_first()
{
	int no,i;
	if(top1==-1)
	{
		printf("Stack is Empty..");
	}
	else
	{
		printf("Enter data you want to search: ");
		scanf("%d",&no);

		for(i=top1; i>=-1 && arr[i]!=no; i--)
		{
		      ;
		}
		if(i!=-1)
		{
			if(arr[i]==no)
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
void peep_last()
{
	int no,i;
	if(top2==max)
	{
		printf("Stack is Empty..");
	}
	else
	{
		printf("Enter data you want to search: ");
		scanf("%d",&no);

		for(i=top2; i>=-1 && arr[i]!=no; i--)
		{
		      ;
		}
		if(i!=-1)
		{
			if(arr[i]==no)
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
void update_first()
{
	int no,i,d;
	if(top1==-1)
	{
		printf("Stack is Empty..");
	}
	else
	{
		printf("Enter data you want to search: ");
		scanf("%d",&no);

		for(i=top1; i>=-1 && arr[i]!=no; i--)
		{
		      ;
		}
		if(i!=-1)
		{
			if(arr[i]==no)
			{
				printf("Enter the new data: ");
				scanf("%d",&d);
				arr[top1] =d;
				printf("Data updated successfully at[%d]",i);
				return;
			}
			printf("%d is Not Found...",no);
			return;
		}

		printf("%d is Not Found...",no);
	}
}
void update_last()
{
	int no,i,d;
	if(top2==max)
	{
		printf("Stack is Empty..");
	}
	else
	{
		printf("Enter data you want to search: ");
		scanf("%d",&no);

		for(i=top2; i>=-1 && arr[i]!=no; i--)
		{
		      ;
		}
		if(i!=-1)
		{
			if(arr[i]==no)
			{
				printf("Enter the new data: ");
				scanf("%d",&d);
				arr[top2] =d;
				printf("Data updated successfully at[%d]",i);
				return;
			}
			printf("%d is Not Found...",no);
			return;
		}

		printf("%d is Not Found...",no);
	}
}

void main()
{
    int choice;

    do
    {
	clrscr();
	printf("\n\t    --------------------------");
	printf("\n\t\tDouble stack Program...");
	printf("\n\n\t\tPress 1: Push first \n\t\tPress 2: Push last \n\t\tPress 3: Pop first  \n\t\tPress 4: Pop last \n\t\tPress 5: Show first \n\t\tPress 6: Show last \n\t\tPress 7: Update first \n\t\tPress 8: Update last \n\t\tPress 9: Peep_first \n\t\tPress 10: Peep_last \n\t\tPress 0: End");
	printf("\n\t    --------------------------");
	printf("\n\nEnter your choice as per above List: ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
		    push_first();
		    getch();
		    break;

		case 2:
		    push_last();
		    getch();
		    break;

		case 3:
		    pop_first();
		    getch();
		    break;

		case 4:
		    pop_last();
		    getch();
		    break;

		case 5:
		    show_first();
		    getch();
		    break;

		case 6:
		    show_last();
		    getch();
		    break;

		case 7:
		    update_first();
		    getch();
		    break;

		case 8:
		    update_last();
		    getch();
		    break;

		case 9:
		    peep_first();
		    getch();
		    break;

		    case 10:peep_last();
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
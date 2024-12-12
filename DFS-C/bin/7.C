#include <stdio.h>
#include<conio.h>
#define size 5
int deque[size];
int f = -1, r = -1;

void insert_front()
{
    int x;
    if((f==0 && r==size-1) || (f==r+1))
    {
	    printf("Queue is full");
    }
    else
    {
	printf("Enter data: ");
	scanf("%d",&x);

	if((f==-1) && (r==-1))
	{
		f=0;
		r=0;
		deque[f]=x;
	}
	else if(f==0)
	{
		f=size-1;
		deque[f]=x;
	}

	else
	{
		f=f-1;
		deque[f]=x;
	}
    }


}


void insert_rear()
{
    int x;
    if((f==0 && r==size-1) || (f==r+1))
    {
	    printf("Queue is full");
    }
    else
    {
	printf("Enter data: ");
	scanf("%d",&x);

	if((f==-1) && (r==-1))
	{
		r=0;
		deque[r]=x;
	}
	else if(r==size-1)
	{
		r=0;
		deque[r]=x;
	}

	else
	{
		r++;
		deque[r]=x;
	}
    }

}


void display()
{
     if(f==-1 && r==-1)
    {
		printf("Deque is empty");
    }
    else
    {
		int i=f;
		printf("\nElements in a deque are: ");

		while(i!=r)
		{
			printf("%d-> ",deque[i]);
			i=(i+1)%size;
		}
       printf("%d->",deque[r]);
     }
}




void delete_front()
{
    if(f==-1 && r==-1)
    {
	printf("Deque is empty");
    }
    else if(f==r)
    {
	printf("\nThe deleted element is %d", deque[f]);
	f=-1;
	r=-1;

    }
    else if(f==(size-1))
    {
	 printf("\nThe deleted element is %d", deque[f]);
	 f=0;
    }
    else
    {
	  printf("\nThe deleted element is %d", deque[f]);
	  f=f+1;
     }
}

void delete_rear()
{
    if((f==-1) && (r==-1))
    {
	printf("Deque is empty");
    }
    else if(f==r)
    {
	printf("\nThe deleted element is %d", deque[r]);
	f=-1;
	r=-1;

    }
    else if(r==0)
    {
	 printf("\nThe deleted element is %d", deque[r]);
	 r=size-1;
    }
    else
    {
	  printf("\nThe deleted element is %d", deque[r]);
	  r=r-1;
     }
}

void modify_first()
{
	int d,i,no;
	if(f==-1 && r==-1)
	{
		printf("\nQueue is Empty..");
	}
	else
	{
		printf("\nEnter data to Modify: ");
		scanf("%d",&no);

		for(i=f;i<=r && deque[i]!=no;i++)
		{

		}
		if(i<=r)
		{
			printf("\nEnter new data: ");
			scanf("%d",&d);

			if(deque[i]==no)
			{
				deque[f]=d;
				printf("\nData is Updated at[%d] index...",i);
				return;
			}
			printf("\nData is Updated at[%d]..",i);
			return;
		}
		printf("Data is not Found..");
	}
}
void modify_last()
{
	int d,i,no;
	if(f==-1 && r==-1)
	{
		printf("\nQueue is Empty..");
	}
	else
	{
		printf("\nEnter data to Modify: ");
		scanf("%d",&no);

		for(i=r;i<=f && deque[i]!=no;i++)
		{
			 ;
		}
		if(i<=r)
		{
			printf("\nEnter new data: ");
			scanf("%d",&d);

			if(deque[i]==no)
			{
				deque[r]=d;
				printf("\nData is Updated..");
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
	printf("\n\t\tDouble Queue Program...");
	printf("\n\n\t\tPress 1: Insert_front \n\t\tPress 2: Insert_rear \n\t\tPress 3: Delete_front  \n\t\tPress 4: Delete_rear \n\t\tPress 5: Display \n\t\tPress 6: Modify_first \n\t\tPress 7: Modify_Last \n\t\tPress 0: End");
	printf("\n\t    --------------------------");
	printf("\n\nEnter your choice as per above List: ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
		    insert_front();
		    getch();
		    break;

		case 2:
		    insert_rear(20);
		    getch();
		    break;

		case 3:
		    delete_front();
		    getch();
		    break;

		case 4:
		    delete_rear();
		    getch();
		    break;

		case 5:
		    display();
		    getch();
		    break;

		case 6: modify_first();
			getch();
			break;
		case 7: modify_last();
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
#include<stdio.h>
#include<conio.h>

#define max 5

int arr[max];
int data=-1;


void add()
{
	int x;

	if (data == max - 1)
	{
		printf("\nArray is full..");
	}
	else
	{
		printf("\nEnter element on Array: ");
		scanf("%d", &x);
		data = data + 1;
		arr[data] = x;
	}
	printf("\n");
}
void del()
{
	if(data==-1)
	{
		printf("\nList is Empty..");
	}
	else
	{
		printf("%d is deleted..",arr[data]);
		data=data-1;
	}
	printf("\n");
}
void modify()
{
	int no,i,d;
	if(data==-1)
	{
		printf("\nList is Empty..");
	}
	else
	{
		printf("Enter data you want to search: ");
		scanf("%d",&no);

		for(i=data; i>=-1 && arr[i]!=no; i--)
		{
		      ;
		}
		if(i!=-1)
		{
			if(arr[i]==no)
			{
				printf("Enter the new data: ");
				scanf("%d",&d);
				arr[i]=d;
				printf("Data updated successfully..");
				return;
			}
			printf("%d is Not Found",no);
			return;
		}

		printf("%d is Not Found",no);


	}
}
void sort()
{
	int i,j,temp;
	if(data==-1)
	{
		printf("\nList is Empty..");
	}
	else
	{
		for(i=0;i<=data;i++)
		{
			for(j=i+1;j<=data;j++)
			{
				if(arr[i] > arr[j])
				{
				    temp=arr[i];
				    arr[i]=arr[j];
				    arr[j]=temp;
				}

			}
		}
		printf("\nSorted List");
		printf("\n");
		for(i=data;i>=0;i--)
		{
			printf("%d->",arr[i]);
		}
	}
}
void display()
{
	int i;
	if(data==-1)
	{
		printf("\nList is Empty..");
	}
	else
	{
		for(i=data;i>=0;i--)
		{
			printf("%d->",arr[i]);
		}
	}
}
void search()
{
	int no,i;
	if(data==-1)
	{
		printf("\nList is Empty..");
	}
	else
	{
		printf("Enter data you want to search: ");
		scanf("%d",&no);

		for(i=data; i>=-1 && arr[i]!=no; i--)
		{
		      ;
		}
		if(i!=-1)
		{
			if(arr[i]==no)
			{
				printf("%d is Found at index[%d]",no,arr[i]);
				return;
			}
			printf("%d is Not Found",no);
			return;
		}

		printf("%d is Not Found",no);


	}
}
void b_search()
{
	int first, last, middle, search;
	if(data==-1)
	{

		printf("List is empty");
	}
	else
	{
		printf("Enter data you want to search: ");
		scanf("%d", &search);

		first = 0;
		last = max-1;
		middle = (first+last)/2;

		while (first <= last)
		{
			if (arr[middle] < search)
			{
				first = middle + 1;
			}
			else if (arr[middle] == search)
			{
				printf("%d found at index [%d].\n", search, middle+1);
				break;
			}
			else
			{
				last = middle - 1;
			}
			middle = (first + last)/2;
		}
		if (first > last)
		{
			printf("Not found!", search);
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
	printf("\n\t\tArray Program...");
	printf("\n\n\t\tPress 1: ADD \n\t\tPress 2: Delete \n\t\tPress 3: Display  \n\t\tPress 4: Sort \n\t\tPress 5: Modify \n\t\tPress 6: Search \n\t\tPress 7: Binary search \n\t\tPress 0: End");
	printf("\n\t    --------------------------");
	printf("\n\nEnter your choice as per above List: ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
		    add();
		    getch();
		    break;

		case 2:
		    del();
		    getch();
		    break;

		case 3:
		    display();
		    getch();
		    break;

		case 4:
		    sort();
		    getch();
		    break;

		case 5:
		    modify();
		    getch();
		    break;

		case 6:search();
			getch();
			break;
		case 7:b_search();
			getch();
			break;

		case 0:
		    exit(0);
		    break;

		default:
		  printf("\nPlease Enter valid choice..");
		  getch();
	}
    } while(1);

}

#include<stdio.h>
#include<conio.h>

struct node
{
	struct node *next;
	int data;
};

int *head;

void insert()
{
	struct node *newnode ,*curr, *prv;
	int ch;
	curr=head;
	prv=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&ch);
	newnode->data=ch;

	while(curr->data < ch && curr!=NULL)
	{
	      prv=curr;
	      curr=curr->next;
	}
	if(head==curr)
	{
		newnode->next=curr;
		head=newnode;
	}
	else
	{
	     prv->next=newnode;
	     newnode->next=curr;
	}

}
void del()
{

}
void display()
{
	struct node *curr,*prv;
	int i;
	curr=head;
	prv=NULL;
	while(curr->next!=NULL)
	{
		prv=curr;
		curr=curr->next;
	}
	for(i=curr;i>=head;i--)
	{
		printf("%d->",i);
	}

}
void main()
{
	int choice;
	do
	{
		clrscr();
		printf("1: Insert\n2: Delete\n3: Display\n0: Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:insert();
				break;
			case 2:del();
				break;
			case 3:display();
				getch();
				break;
			case 0:exit();
				break;
		}
	}while(1);
}

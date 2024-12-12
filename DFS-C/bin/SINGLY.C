#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node* next;
};

struct node*head=NULL;
void insert()
{
	int d;
	struct node*newnode,*curr=head,*p=NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&d);
	newnode->data=d;
	if(head==NULL)
	{

	newnode->next=NULL;
	head=newnode;
	}
	else
	{
		while(curr!=NULL && curr->data < d)
		{
			p=curr;
			curr=curr->next;
		}
		if(head==curr)
		{
			newnode->next=head;
			head=newnode;
		}
		else
		{
			newnode->next=curr;
			p->next=newnode;
		}
	}

}
void remov()
{
	int d;
	struct node *curr=head,*p=NULL;
	printf("Enter data to delete:");
	scanf("%d",&d);
	if(head==NULL)
	{
		printf("\n List is empty");
	}
	else
	{
		while(curr!=NULL && curr->data != d)
		{
			p=curr;
			curr=curr->next;
		}
		if(head==curr)
		{
			head=curr->next;
		}
		else if(curr!=NULL)
		{
			p->next=curr->next;
		}
		else
		{
			printf("\nElement not found");
		}
		if(curr!=NULL)
		{
			printf("%d is deleted...",curr->data);
			free(curr);
		}
	}
}
void display()
{
   struct node*temp=head;
   if(head==NULL)
   {
    printf("\nList is Empty");
   }
   else
   {
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}

   }
}

void main()
{
	int choice;
	do
	{
		clrscr();
		printf("Singly linked-list program");
		printf("\n1.Insert \n2.Delete \n3.Display  \n0.Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:insert();
				getch();
				break;
			case 2: remov();
				getch();
				break;
			case 3: display();
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

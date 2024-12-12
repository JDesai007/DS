#include<stdio.h>
#include<conio.h>

struct node{
int data;
struct node* next;

};
struct node *head;

void insert()
{
 struct node *newnode, *curr,*prv;
 int ele;
 curr=head;
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("Enter data:");
 scanf("%d",&ele);
 newnode->data=ele;
 newnode->next=NULL;

 while(curr->data < ele && curr!=NULL)
 {
	prv=curr;
	curr=curr->next;
 }

 if(head!=NULL)
 {
	prv->next=newnode;
	newnode->next=curr;
 }
 else
 {
	curr=ele;
	head=ele;
	curr->next=NULL;
 }
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
	if(curr==NULL)
	{
		printf("List is empty");
	}
	else
	{
		for(i=curr;i>=head;i--)
		{
			printf("%d->",i);
		}
	}

}

void main()
{
	int choice;
	do
	{
		clrscr();
		  printf("1:insert \n2.display \n0:Exit");
		  printf("\n\nEnter your choice:");
		  scanf("%d",&choice);

		  switch(choice)
		  {
			case 1:insert();
				break;
			case 2:display();
				getch();
				break;

			case 0:exit(0);
				break;
		  }
	}while(1);
	insert();
	getch();

}
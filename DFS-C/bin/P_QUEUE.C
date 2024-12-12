#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 5

//proto tyep's
void insert(int q[],int *f,int *r,int e,char msg[]);
void del(int q[],int *f,int *r);
void display(int q[],int *f,int *r,int q2[],int *f2,int *r2);
void main()
{
	//var for queue
	int q[max],q2[max],choice;
	int *f=-1,*r=-1,*f2=-1,*r2=-1;
	clrscr();


	do{
			printf("\nenter 1 for inset	\nenter 2 for delete	\nenter 3 for display	\netner 4 for exit	\nenter your choice :-  ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{       int e;
			printf("enter your value :- ");
			scanf("%d",&e);
			if(e>=60)
			{
				insert(q,&f,&r,e,"senior queue");
			}
			else
			{
				insert(q2,&f2,&r2,e,"regular queue");
			}
			break;
		}
		case 2:
		{
			del(q,&f,&r);
			break;
		}
		case 3:
		{
			display(q,&f,&r,q2,&f2,&r2);
			break;
		}
		default :{
			printf("\nunvailide choice");}
	}
	}while( (choice == 1) || (choice == 2) || (choice == 3) );
}
void insert(int qq[],int *ff,int *rr,int e,char name_q[20])
{
	//printf("\n i am insert");
	if(*rr == max)
	{
		printf("\n%s if over flow",name_q);
	}
	else if(*ff == -1 && *rr == -1)
	{
		*ff=*rr=0;
		qq[*rr]=e;
		*rr += 1;
	}
	else
	{
		qq[*rr]=e;
		*rr += 1;
	}
}
void del(int q[],int *f,int *r)
{
	int deleted_ele=0;
	//	printf("\n i am delete");

	if(*f == - 1 || *f == *r)
	{
		printf("\nqueue is empty");
	//	exit(0);
	}
	else
	{
		 deleted_ele= q[*f];
		 printf("you delete :- %d",deleted_ele);
		*f += 1;
	}
	if(*f == *r)
		*f = *r = -1;
}
void display(int q[],int *f,int *r,int q2[],int *f2,int *r2)
{
	//printf("\n i am dispaly");
	if(*f == - 1 || *f == *r)
		printf("\nsenior queue is empty");
	else
	{
		int i;
		printf("\nsenior queue ->");
		for(i=*f;i<*r;i++)
		{
			printf("\nvalue at queue[%d] :- %d",i,q[i]);
		}
	}

	if(*f2 == - 1 || *f2 == *r2)
		printf("\nregular queue is empty");
	else
	{
		int i;
		printf("\nregular queue -> ");
		for(i=*f2;i<*r2;i++)
		{
			printf("\nvalue at queue[%d] :- %d",i,q2[i]);
		}
	}


}
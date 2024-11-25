#include<stdio.h>
#include<conio.h>
#include<string.h>

struct std
{
     int no;
     char name[20];
     int mark;
}s[10];

 void getdata();
 void sort();
 void display();

void main()
{

	clrscr();
	getdata();
	sort();
	display();
	getch();


}

void getdata()
{
	int i;
	printf("Enter data for student...");

	for(i=0;i<3;i++)
	{
	  printf("\nEnter roll no:%d ",i+1);

	  printf("\nEnter name of student: ");
	  scanf("%s",&s[i].name);

	  printf("Enter marks of student: ");
	  scanf("%d",&s[i].mark);

	  printf("\n");

	}
}

void sort()
{
	int i,j,temp;
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(s[i].mark < s[j].mark)
			{
			    temp=s[i].mark;
			    s[i].mark=s[j].mark;
			    s[j].mark=temp;
			}
		}
	}
}

void display()
{
	int i;
	for(i=0;i<3;i++)
	{
	  printf("roll no: %d",i+1);

	  printf("\nname of student: %s",s[i].name);

	   printf("\nmarks of student: %d",s[i].mark);

	  printf("\n");


	}

}

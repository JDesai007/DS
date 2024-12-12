#include<stdio.h>
#include<conio.h>

void main()
{
 int a[5];
 int i,j,x;
 clrscr();
 for(i=0;i<5;i++)
 {
	printf("Enter data:");
	scanf("%d",&x);
	j=i-1;
	while(x < a[j] && j>=0)
	{
		a[j+1]=a[j];
		j--;
	}
	a[j+1]=x;
 }
 for(i=0;i<5;i++)
 {
	printf("%d ",a[i]);
 }
 getch();
}

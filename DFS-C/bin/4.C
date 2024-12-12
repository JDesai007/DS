#include<stdio.h>
#include<conio.h>

#include<ctype.h>

char stack[10];
int top=-1;

void push(char x)
{
	stack[++top]=x;
}

char pop()
{
	if(top==-1)
	{
		return -1;
	}
	else
	{
		return stack[top--];
	}
}

int priority(char x)
{
	if(x=='+' || x=='-')
	{
		return 1;
	}
	if(x=='*' || x=='/')
	{
		return 2;
	}
}

void main()
{
	char exp[20];
	char *e,x;
	clrscr();
	printf("Enter the Expression: ");
	scanf("%s",exp);
	e=exp;

	while(*e!= '\0')
	{
		if(isalnum(*e))
		{
			printf("%c",*e);
		}

		else 
		{
			while(priority(stack[top]) >= priority(*e))
			{
				printf("%c",pop());
			}
			push(*e);
		}
		e++;
	}
	
	while(top != -1)
	{
		printf("%c",pop());
	}
	getch();
}

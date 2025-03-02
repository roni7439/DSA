#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top=-1;
int stack_arr[MAX];
void push(int data)
{
	if(top==MAX-1)
	{
		printf("\n%d is overflow from stack",data);
	}
	else
	{
		top++;
		stack_arr[top]=data;
	}
}

int pop()
{
	int value;
	if(top==-1)
	{
		printf("\nEmpty");
	}
	else
	{
		value=stack_arr[top];
		top--;
	}
}

void display()
{
	if(top==-1)
	{
		printf("EMpty Stack");
		exit(1);
	}
	else
	{
		printf("\nStack Element is: ");
		for(int i=top;i>=0;i--)
		{
			printf("%d\t",stack_arr[i]);
		}
	}
}

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	display();
	int data;
	data=pop();
	data=pop();
	data=pop();
	display();
	return 0;
}

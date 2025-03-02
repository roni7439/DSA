#include<stdio.h>
#include<stdlib.h>
#define MAX 4


int stack_arr[MAX];
int top=-1;

int isFull()
{
	if(top==MAX-1)
	{
		return 1;
	}
	return 0;
	
}

int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	return 0;
	
}


void push(int data)
{
	if(isFull())
	{
		printf("\nThe Stack is overflow");
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
	if(isEmpty())
	{
		printf("\nThe Stack is UnderFlow");
		exit(1);
	}
	else
	{
		value=stack_arr[top];
		top--;
	}
	return value;
	
}

int peek()
{
	if(isEmpty())
	{
		printf("\nThe Stack is underflow");
		exit(1);
	}
	else
	{
		return stack_arr[top];
	}
}


void display()
{
	int i;
	if(isEmpty())
	{
		printf("\nThe stack is underflow");
		exit(1);
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d\t",stack_arr[i]);
		}
	}
	
}


int main()
{
	int choice,data;
	while(1)
	{
		printf("\npush 1->\npop 2->\npeek 3->\nPrintf the stak element 4->\npress 5 to exit->");
		printf("\nEnter Your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter the data: ");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				data=pop();
				break;
			case 3:
			    
				data=peek();
				printf("\nTopmost Element of the stack: %d",data);
				break;
			case 4:
			    display();
				break;
			case 5:
			    exit(1);
				break;
			default:
			    printf("\nWrong choice");	
			    	
		}
	}
	return 0;
}

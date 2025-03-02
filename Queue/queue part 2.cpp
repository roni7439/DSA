#include<stdio.h>
#define MAX 4
int quenue[MAX];
int front=-1,rare=-1;

int isfull()
{
	return (rare==MAX-1);
}

int isempty()
{
	return (front==-1);
}

void enque()
{
	if(isfull())
	{
		printf("\nThe Qunue is Overflow");
	}
	else
	{
		int data;
		printf("\nEnter The Data: ");
		scanf("%d",&data);
		
		if(isempty())
		{
			front=rare=0;
		}
		else
		{
			rare++;
		}
		quenue[rare]=data;
		printf("\nData inserted successfully");
	}
}

void deque()
{
	if(isempty())
	{
		printf("\nThe Quenue is Underflow");
	}
	else
	{
		printf("\nThe Deleted Data is %d",quenue[front]);
		if(rare==front)
		{
			rare=front=-1;
		}
		else
		{
			front++;
		}
	}
	
}

void display()
{
	if(isempty())
	{
		printf("\nThe Quenue is underflow");
	}
	else
	{
		printf("\nThe Eements are: ");
		for(int i=front;i<=rare;i++)
		{
			printf("%d\t",quenue[i]);
		}
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->Enque\n2-->Deque\n3-->Display\nEnter Your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				enque();
				break;
			case 2:
			    deque();
				break;
			case 3:
			    display();
				break;
			default:
			    printf("\n-----Wrong-----");		
		}
	}
}

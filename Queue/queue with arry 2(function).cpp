#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1,rare=-1;

int isFull()
{
	return(rare==MAX-1);
}

int isEmpty()
{
	return (front==-1);
}

void enqueue()
{
	if(isFull())
	{
		printf("\nThe Qqueue is Overflow");
	}
	else
	{
		int data;
		printf("\nEnter The Data: ");
		scanf("%d",&data);
		if(isEmpty())
		{
			rare=front=0;
		}
		else
		{
			rare++;
		}
		queue[rare]=data;
	}
}

void dequeue()
{
	if(isEmpty())
	{
		printf("\nQueue is Underflow");
	}
	else
	{
		printf("\nDeleted Data is %d",queue[front]);
		if(rare==front)
		{
			front=rare=-1;
		}
		else
		{
			front++;
		}
	}
}

void display()
{
	if(isEmpty())
	{
		printf("\nThe Queue is Underflow");
	}
	else
	{
		printf("\nThe Queue Elements Are: ");
		for(int i=front;i<=rare;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->Enqueue\n2-->Dequeue\n3-->Display\nEnter Your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
			    display();
				break;
			default:
			    printf("\n---Stop----");
						
		}
	}
}

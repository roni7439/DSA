#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int queue[SIZE];
int f=-1,r=-1;
int isfull()
{
	return (r+1)%SIZE==f;
}
int  isempty()
{
	return f==-1;
}

void enqueue()
{
	if(isfull())
	{
		printf("\nQueue is Overflow");
	}
	else
	{
		int data;
		printf("\nEnter The Data: ");
		scanf("%d",&data);
		if(isempty())
		{
			r=f=0;
		}
		else
		{
			r=(r+1)%SIZE;
		}
		queue[r]=data;
	}
}

int dequeue()
{
	if(isempty())
	{
		printf("\nQueue is Empty");
		return -1;
	}
	else
	{
		int value;
		value=queue[f];
		if(r==f)
		{
			r=f=-1;
		}
		else
		{
			f=(f+1)%SIZE;
		}
		return value;
	}
}

void display()
{
	if(isempty())
	{
		printf("\nQueue is Empty");
	}
	else
	{
		int i=f;
		printf("\nQueue Element are: ");
		while(1)
		{
		    printf("%d ",queue[i]);
		    if(i==r)
		    {
		        break;
		    }
		    i=(i+1)%SIZE;
		}
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->Enqeue\n2-->Dequeue\n3-->Display\nEnter Your Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
			    printf("\nDeleted Data is %d",dequeue());
				break;
			case 3:
			    display();
				break;
			default:
			    printf("\nWrong choice");			
		}
	}
	return 0;
}

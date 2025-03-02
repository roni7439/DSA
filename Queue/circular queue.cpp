//circular Queue;

#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int f=-1,r=-1;

int isfull()
{
	return (r+1)%SIZE==f;
}

int isempty()
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
		int value;
		printf("\nEnter The Value: ");
		scanf("%d",&value);
		if(isempty())
		{
			f=0;
		}
		r=(r+1)%SIZE;
		queue[r]=value;
		printf("Item Inserted");	
	}
}

int dequeue()
{
	if(isempty())
	{
		printf("\nQueue is Empty");
	}
	else
	{
		int value;
		value=queue[f];
		if(r==f)
		{
			f=r=-1;
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
		printf("Queue Elements Are: ");
		int i=f;
		while(1)
		{
			printf("%d\t",queue[i]);
			if(i==r)
			{
				break;
			}
			else
			{
				i=(i+1)%SIZE;
			}
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
			    printf("\nDeleted Item %d",dequeue());
				break;
			case 3:
			    display();
				break;
			default:
			    printf("\nWrong Choice");			
		}
	}
	return 0;
}

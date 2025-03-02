#include<stdio.h>
#define SIZE 3
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
		printf("\nThe Queue is Overflow");
	}
	else
	{
		int value;
		printf("\nEnter The Value: ");
		scanf("%d",&value);
		if(isempty())
		{
			r=f=0;
		}
		else
		{
			r=(r+1)%SIZE;
		}
		queue[r]=value;
		printf("Data isterted\n");
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
		if(f==r)
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
		int i=f;
		printf("\nQueue Elements Are: ");
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
		printf("\n1-->enqueue\n2-->dequeue\n3-->display\nEnter Your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
			    printf("\nDeleted Element is %d",dequeue());
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

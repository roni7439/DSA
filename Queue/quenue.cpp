#include<stdio.h>
#define MAX 5
int quenue[MAX];
int rare=-1,front=-1;

void enqueue()
{
	if(rare==MAX-1)
	{
		printf("\nThe Quenue is Overflow");
	}
	else
	{
		int data;
		printf("\nEnter The Data: ");
		scanf("%d",&data);
		if(front==-1)
		{
		   front=rare=0;
		}
		else
		{
			rare++;
		}
		quenue[rare]=data;
		
	}
}

void dequeue()
{
	if(front==-1)
	{
		printf("\nThe Quenue is Empty");
	}
	else
	{
		printf("\nThe deleted Element is %d",quenue[front]);
		if(front==rare)
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
	if(front==-1)
	{
		printf("\nThe Quenue is Underlow");
	}
	else
	{
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
		printf("\n1-->Enqueue\n2-->Dequeue\n3-->Display\nEnter your choice: ");
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
			   printf("\n-----Wrong Choice-----");			
		}
	}
	return 0;
}

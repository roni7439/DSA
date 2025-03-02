#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int F=-1,R=-1;

void enqueue(int data)
{
	if(R==+MAX-1)
	{
		printf("\nThe Queue is Overflow");
	}
	else if(F==-1 && R==-1)
	{
		
		F=R=0;
	}
	else
	{
		R++;
	}
	queue[R]=data;
	printf("\nItem Inserted");
}

int dequeue()
{
	int val;
	if(F==-1)
	{
		printf("\nThe Queue Is Underflow");
	}
	else
	{
	    val=queue[F];
		if(F==R)
		{
			F=R=-1;
		}
		else
		{
			F++;
		}	
	}
	return val;
}
void display()
{
	printf("\nThe Queue Elements Are: ");
	for(int i=F;i<=R;i++)
	{
		printf("%d ",queue[i]);
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->Enqueue\n2-->Dequeue\n3-->Display\nEnter Your Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				int data;
				printf("\nEnter The Data: ");
				scanf("%d",&data);
				enqueue(data);
				break;
			case 2:
				printf("\nDeleted Item is %d",dequeue());
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


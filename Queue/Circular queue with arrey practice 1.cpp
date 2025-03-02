#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int queue[MAX];
int F=-1,R=-1;
void enqueue(int data)
{
	if((R+1)%MAX==F)
	{
		printf("\nThe Queue is Full");
	}
	else
	{
		if(F==-1)
		{
			F=R=0;
		}
		R=(R+1)%MAX;
		queue[R]=data;
		printf("\nItem Inserted");
	}
}
int dequeue()
{
	if(F==-1)
	{
		printf("\nThe Queue Is empty");
		return 0;
	}
	else
	{
		int value=queue[F];
		if(F==R)
		{
			F=R=-1;
		}
		else
		{
			F=(F+1)%MAX;
		}
		return value;
	}
}
void display()
{
	if(F==-1)
	{
		printf("\nThe Queue Is Empty");
	}
	else
	{
		printf("\nThe Queue Elements Are: ");
		int i=F;
		while(1)
		{
			printf("%d ",queue[i]);
			if(i==R)
			{
				break;
			}
			i=(i+1)%MAX;
		}
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->Enqueue\n2-->Dequeue\n3-->Display\nEnter The Choice: ");
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
			    printf("\nDeleted Item Is %d",dequeue());
				break;
			case 3:
			    display();
				break;
			default:
			   printf("\nYou are Entered Wrong Choice....");			
		}
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};
struct queue *F=NULL;
struct queue *R=NULL;
typedef struct queue node;
void enqueue(int data)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
	{
		printf("\nMemory Allocation failed");
	}
	else
	{
		newnode->data=data;
		newnode->next=NULL;
		if(F==NULL && R==NULL)
		{
			R=F=newnode;
			R->next=F;	
		}
		else
		{
			R->next=newnode;
			R=newnode;
			newnode->next=F;
		}
	}
}
int dequeue()
{
	node *temp;
	int value;
	temp=F;
	if(F==NULL)
	{
		printf("\nThe Queue is Empty");
		return 0;
	}
	else
	{
		if(F==R)
		{
			F=R=NULL;
			value=temp->data;
			free(temp);
			temp=NULL;
		}
		else
		{
			value=temp->data;
			F=temp->next;
			free(temp);
			temp=NULL;			
		}
		return value;
	}
}
void display()
{
	node *dis;
	dis=F;
	if(dis==NULL)
	{
		printf("\nThe Queue Is Empty");
	}
	else
	{
		printf("\nThe Data Elements are: ");
		do
		{
			printf("%d ",dis->data);
			dis=dis->next;
		}while(dis != F);
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->Enqueue\n2-->Dequeue\n3-->Display\nEnter Your choice-: ");
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
			    printf("\nYou are entered wrong choice..");			
		}
	}
	return 0;
}

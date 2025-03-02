#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};

struct queue *r=NULL;
struct queue *f=NULL;

typedef struct queue node;

void enqueue(int x)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	
	if(newnode==NULL)
	{
		printf("\nThe Queue is Full");
		exit(1);
	}
	else
	{
		newnode->data=x;
		newnode->next=NULL;
		
		if(f==NULL && r==NULL)
		{
			f=r=newnode;
			newnode->next=f;
		}
		else
		{
			r->next=newnode;
			r=newnode;
			newnode->next=f;
		}
	}
}

int dequeue()
{
	node *tmp;
	int value;
	tmp=f;
	value=tmp->data;
	if(f==NULL)
	{
		printf("\nQueue is Empty");
		exit(1);
	}
	else if(f==r)
	{
		f=r=NULL;
	}
	else
	{
		f=f->next;
		r->next=f;
	}
	return value;
}

void display()
{
	node *dis;
	dis=f;
	if(dis == NULL)
	{
		printf("\nThe Queue is Empty");
	}
	else
	{
		printf("\nData Elements Are: ");
		do
		{
			printf("%d ",dis->data);
			dis=dis->next;
		}
		while(dis != f);
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
				int data;
				printf("\nEnter The Data: ");
				scanf("%d",&data);
			   enqueue(data);
			   break;
			case 2:
			   printf("Deleted Item is %d",dequeue());
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

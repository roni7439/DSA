#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};
struct queue *f=NULL;
struct queue *r=NULL;

void enqueue()
{
	struct queue *newnode;
	newnode=(struct queue*)malloc(sizeof(struct queue));
	if(newnode==NULL)
	{
		printf("\nMemory Allcation Failed");
	}
	else
	{
		int data;
		printf("\nEnter The Data: ");
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=NULL;
		if(r==NULL && f==NULL)
		{
			r=f=newnode;
			r->next=f;
		}
		else
		{
			r->next=newnode;
			r=newnode;
			r->next=f;
		}
	}
}

int dequeue()
{
	struct queue *temp;
	temp=f;
	if(f==NULL)
	{
		printf("\nQueue is empty");
	}
	else if(r==f)
	{
		r=f=NULL;
		free(temp);
		temp=NULL;
	}
	else
	{
		int value;
		f=f->next;
		value=temp->data;
		free(temp);
		temp=NULL;
		
		return value;
	}
}

void display()
{
	struct queue *dis;
	dis=f;
	if(dis == NULL)
	{
		printf("\nQueue is Empty");
	}
	else
	{
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
		printf("\n1-->Enqueue\n2-->Dequeue\n3-->isplay\nEnter Your choice: ");
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

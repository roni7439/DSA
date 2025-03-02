#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};
struct queue *F,*R;
struct queue node;

void enqueue()
{
	struct queue *newnode;
	newnode=(struct queue*)malloc(sizeof(struct queue));
	if(newnode==NULL)
	{
		printf("\nMemory Allocation Failed");
	}
	else
	{
		int data;
		printf("\nEnter The Data: ");
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=NULL;
		if(F==NULL && R==NULL)
		{
			F=R=newnode;
		}
		else
		{
			R->next=newnode;
			R=newnode;
		}
	}
}

int dequeue()
{
	struct queue *tmp;
	if(F==NULL)
	{
		printf("\nQueue is Empty");
	}
	else
	{
		tmp=F;
		int value;
		F=F->next;
		value=tmp->data;
		free(tmp);
		tmp=NULL;
		
		return value;
	}
}

void display()
{
	struct queue *dis=F;
	if(dis == NULL)
	{
		printf("\nQueue is Empty");
	}
	else
	{
		while(dis != NULL)
		{
			printf("%d\t",dis->data);
			dis=dis->next;
		}
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->enqueue\n2-->dequeue\n3-->display\nEnter Your Choice: ");
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
			    printf("\nWrong Choice");			
		}
	}
	
	return 0;
 } 

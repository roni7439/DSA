#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
};
typedef struct list node;
node *F=NULL,*R=NULL;
void enqueue(int data)
{
	node *newnode,*temp;
	newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
	{
		printf("\nAllocation Failed");
	}
	else
	{
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
	   printf("\nSuccessfuly Data Inserted");
	}
}

int dequeue()
{
	node *temp;
	if(F==NULL)
	{
		printf("\nThe Queue Is Empty");
	}
	else
	{
		temp=F;
		int value=temp->data;
		F=temp->next;
		free(temp);
		temp=NULL;
		return value;
	}
}

void display()
{
	node *dis;
	dis=F;
	if(dis == NULL)
	{
		printf("\nThe Queue Is Empty");
	}
	else
	{
		printf("\nThe Queue Elements Are: ");
		while(dis != NULL)
		{
			printf("%d ",dis->data);
			dis=dis->next;
		}
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
			    printf("\nDeleted Item Is: %d",dequeue());
				break;
			case 3:
			    display();
				break;
			default:
			    printf("\nEnter The Right Choice...");			
		}
	}
	return 0;
}

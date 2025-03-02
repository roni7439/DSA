#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue *next;
} ;

struct queue *r=NULL;
struct queue *f=NULL;

typedef struct queue node;

void enqueue(int x)
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    
    if(newnode==NULL)
    {
        printf("\nMemory Allocation Failed");
    }
    else
    {
        newnode->data=x;
        newnode->next=NULL;
        
        if(r==NULL && f==NULL)
        {
            r=f=newnode;
        }
        else
        {
            r->next=newnode;
            r=newnode;
        }
    }
}

int dequeue()
{
    node *tmp;
    tmp=f;
    int value;
    if(f==NULL)
    {
        printf("\nThe Queue is Empty");
        exit(1);
    }
    else if(f==r)
    {
        value=f->data;
        f=r=NULL;
        free(tmp);
        return value;
    }
    else
    {
        f=f->next;
        value=tmp->data;
        free(tmp);
        tmp=NULL;
        return value;
    }
}

void display()
{
	node *dis;
	dis=f;
	if(dis==NULL)
	{
		printf("\nThe Queue is empty");
		exit(1);
	}
	else
	{
		printf("\nThe Queue Elements are: ");
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
              printf("\nThe Deleted Item Is: %d",dequeue());
              break;
            case 3:
			  display();
			  break;  
            default:
              printf("\nWrong choice");
        }
    }
}

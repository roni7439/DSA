//push in stack with link list
#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *link;
}* top=NULL;
typedef struct stack node;

void push(int data)
{
	node *newnode;
	newnode =(node*)malloc(sizeof(node));
	if(newnode == NULL)
	{
		printf("\nStack is Empty");
	}
	else
	{
		newnode->data=data;
		newnode->link=top;
		top=newnode;
	}
}

void print()
{
	node *tmp=top;
	printf("\nStack Element is: ");
	while(tmp != NULL)
	{
		printf("%d\t",tmp->data);
		tmp=tmp->link;
	}
	
}

int main()
{
	int choice,data;
	while(1)
	{
		printf("\n1. push\n2. print\n3. Exit");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter The Data: ");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
			    print();
				break;
			case 3:
			    exit(1);
				break;
		    default :
			   printf("\nWrong choice");				
		}
	}
	return 0;
	
}

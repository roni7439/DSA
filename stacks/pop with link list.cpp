//pop with link list
#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
}*top=NULL;
typedef struct stack node;

int isEmpty()
{
	if(top==NULL)
	{
		return 1;
	}
	return 0;
}

void push(int data)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
	{
		printf("\nStack is overflow");
		exit(1);
	}
	else
	{
		newnode->data=data;
		newnode->next=top;
		top=newnode;
	}
}

int pop()
{
	node *tmp;
	if(isEmpty())
	{
		printf("\nThe Stack is Underflow");
		exit(1);
	}
	else
	{
		tmp=top;
		int value;
		value=tmp->data;
		top=top->next;
		free(tmp);
		tmp=NULL;
		
		return value;
		
	}
}

int peek()
{
	if(isEmpty())
	{
		printf("\nThe stack is underflow");
		exit(1);
	}
	return top->data;
}


void display()
{
	node *dis;
	dis=top;
	printf("\nStack Elements are: ");
	while(dis != NULL)
	{
		printf("%d\t",dis->data);
		dis=dis->next;
	}
}

int main()
{
	int data,choice;
	while(1)
	{
		printf("\n1. push\n2. pop\n3. print\n4. Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter The Data: ");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
			    pop();
				printf("\npoped value is %d ",pop());
				break;
			case 3:
			    display();
				break;
			case 4:
			    exit(1);
				break;
			default:
			    printf("\nWrong choice");				
		}
	}
	return 0;
}



















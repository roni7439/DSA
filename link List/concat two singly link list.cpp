#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
}*start1=NULL,*start2=NULL;
typedef struct list node;

void create1()
{
	node *newnode,*tmp;
	newnode=(node*)malloc(sizeof(node));
	printf("\nEnter The Node1 data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(start1==NULL)
	{
		start1=newnode;
	}
	else
	{
		tmp=start1;
		while(tmp->next != NULL)
		{
			tmp=tmp->next;
		}
		tmp->next=newnode;
	}
}


void create2()
{
	node *newnode,*tmp;
	newnode=(node*)malloc(sizeof(node));
	printf("\nEnter The Node2 data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(start2==NULL)
	{
		start2=newnode;
	}
	else
	{
		tmp=start2;
		while(tmp->next != NULL)
		{
			tmp=tmp->next;
		}
		tmp->next=newnode;
	}
}

void concatinate()
{
	node *tmp1;
	if(start1==NULL)
	{
		start1=start2;
	}
	else
	{
		tmp1=start1;
		while(tmp1->next != NULL)
		{
			tmp1=tmp1->next;
		}
		tmp1->next=start2;
	}
}

void display()
{
	node *tmp;
	tmp=start1;
	if(tmp == NULL)
	{
		printf("\nEmpty");
		exit(1);
	}
	else
	{
		while(tmp != NULL)
		{
			printf("%d\t",tmp->data);
			tmp=tmp->next;
		}
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n1.-> create 1\n2.-> create 2\n3.-> concatinate\n4.->display");
		printf("\nEnter Your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create1();
				break;
			case 2:
			    create2();
			    break;
			case 3:
			    concatinate();
				break;	
			case 4:
				display();
			    break;
			default:
			    printf("\nWrong choice");					
		}
	}
	return 0;
}

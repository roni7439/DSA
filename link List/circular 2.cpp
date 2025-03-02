#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
}*head=NULL;

typedef struct list node;

void create(int x)
{
	node *newnode,*tmp;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=x;
	newnode->next=NULL;
	
	if(head==NULL)
	{
		head=newnode;
		head->next=head;
	}
	else
	{
		tmp=head;
		while(tmp->next != head)
		{
			tmp=tmp->next;
		}
		tmp->next=newnode;
		newnode->next=head;
	}
}

void insert_pos(int pos,int x)
{
	node *newnode,*tmp;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=x;
	newnode->next=NULL;
	
	if(head==NULL)
	{
		newnode->next=head;
		head->next=head;
		head=newnode;
		
	}
	else
	{
		tmp=head;
		for(int i=1;i<pos-1;i++)
		{
			tmp=tmp->next;
		}
		newnode->next=tmp->next;
		tmp->next=newnode;
	}
	
}

void display()
{
	node *dis;
	dis=head;
	if(dis == NULL)
	{
		printf("\nEmpty List");
	}
	else
	{
		printf("\nElements Are: ");
		do
		{
			printf("%d\t",dis->data);
			dis=dis->next;
		}while(dis != head);
	}
}


int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->Create\n2-->Display\n3-->Insert At Any Position\nEnter Your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				int data;
				printf("\nEnter The Data: ");
				scanf("%d",&data);
				create(data);
				break;
			case 2:
			    display();
				break;
			case 3:
				int data1,pos;
				printf("\nEnter The Position: ");
				scanf("%d",&pos);
				printf("\nEnter The Data: ");
				scanf("%d",&data);
				insert_pos(pos,data);
				break;	
			default:
			    printf("\nWrong Choice");		
		}
	}
	return 0;
}

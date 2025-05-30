//Circular Link List;

#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *next;
} *head=NULL;

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

void create_first(int x)
{
	node *newnode,*tmp;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=x;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=head;
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
		head=newnode;
	}
}

void create_any_pos(int x,int y)
{
	node *newnode,*tmp;
	newnode=(node*)malloc(sizeof(node));
	newnode->next=NULL;
	newnode->data=x;
	tmp=head;
	for(int i=1;i<y-1;i++)
	{
		tmp=tmp->next;
	}
	newnode->next=tmp->next;
	tmp->next=newnode;
}

void display()
{
	node *dis;
	dis=head;
	if(dis==NULL)
	{
		printf("\nEmpty List");
	}
	else
	{
		printf("\nList Elements Are: ");
		do
		{
			printf("%d\t",dis->data);
			dis=dis->next;
		}
		while(dis != head);
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->create\n2-->display\n3-->Insert At First\nEnter Your choice: ");
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
				int data1;
				printf("\nEnter The Data At First: ");
				scanf("%d",&data1);
				create_first(data1);
				break;
			case 4:
				int value,pos;
				printf("\nEnter The POsition: ");
				scanf("%d",&pos);
				printf("\nEnter The Data At First: ");
				scanf("%d",&value);
				create_any_pos(value,pos);
				break;	
			default:
			    printf("\nWrong choice......");		
		}
	}
	return 0;
}

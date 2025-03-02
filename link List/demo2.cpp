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
	}
	else
	{
		tmp=head;
		while(tmp->next != NULL)
		{
			tmp=tmp->next;			
		}
		tmp->next=newnode;
	}
}



void sorting()
{
	node *tmp,*tmpn;
	int value_tmp;
	tmp=head;
	while(tmp != NULL)
	{
		tmpn=tmp->next;
		while(tmpn != NULL)
		{
			if(tmp->data > tmpn->data)
			{
				value_tmp=tmp->data;
				tmp->data=tmpn->data;
				tmpn->data=value_tmp;
			}
			tmpn=tmpn->next;
		}
		tmp=tmp->next;
	}
	
}

void searching(int x)
{
	node *tmp;
	tmp=head;
	int i=1;
	while(tmp->next != NULL)
	{
		if(x==i)
		{
			printf("\nPosition %d : value %d ",i,tmp->data);
		}
		i++;
		tmp=tmp->next;
	}
	
}

void display()
{
	node *dis;
	dis=head;
	
	if(dis==0)
	{
		printf("\nThe List Is Empty");
	}
	else
	{
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
		printf("\n1-->create\n2-->display\n3-->sorting\n4-->searching\nEnter Your choice: ");
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
			    sorting();
				break;
			case 4:
				int pos;
				printf("\nEnter The position: ");
				scanf("%d",&pos);
			    searching(pos);
				break;
			default:
			    printf("\nWrong choice");				
		}
	}
	return 0;
}

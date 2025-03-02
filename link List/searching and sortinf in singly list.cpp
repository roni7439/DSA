#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
}*start=NULL;
typedef struct list node;
void create()
{
	node *newnode,*tmp;
	newnode=(node *)malloc(sizeof(node));
	printf("\nEnter The node Data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		tmp=start;
		while(tmp->next != NULL)
		{
			tmp=tmp->next;
		}
		tmp->next=newnode;
	}
}

void sorting()
{
	node *tmp,*ctmp;
	int tmpr;
	tmp=start;
	while(tmp!=NULL)
	{
		ctmp=tmp->next;
		while(ctmp != NULL)
		{
			if(tmp->data > ctmp->data)
			{
				tmpr=tmp->data;
				tmp->data=ctmp->data;
				ctmp->data=tmpr;
			}
			ctmp=ctmp->next;
		}
		tmp=tmp->next;
	}	
}

void searching()
{
	node *tmp;
	int pos,i=0;
	printf("\nEnter The position: ");
	scanf("%d",&pos);
	if(tmp == NULL)
	{
		printf("\Empty");
	}
	else
	{
		tmp=start;
		while(tmp != NULL)
		{
			if(pos==i)
			{
				printf("\nThe posined value is: %d",tmp->data);
			}
			i++;
			tmp=tmp->next;
		}
	}
}

void display()
{
	node *dis;
	dis=start;
	if(dis == NULL)
	{
		printf("\nEmpty");
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
		printf("\ncreate-->1\nsorting-->2\nsearching-->3\ndisplay-->4\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
			    sorting();
			    break;
			case 3:
			    searching();
				break;
			case 4:
			    display();
				break;
			default:
			    printf("\nWriong choice");		   
		}
	}
	return 0;
}

//search in Link List

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
	newnode=(node*)malloc(sizeof(node));
	newnode->next=NULL;
	printf("Enter The Data:  ");
	scanf("%d",&newnode->data);
	
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


void search()
{
	node *tmp;
	int i=0,pos;
	printf("\nEnter position: ");
	scanf("%d",&pos);
	tmp=start;
	if(tmp==NULL)
	{
		printf("\nEmpty");
	}
	else
	{
		while(tmp != NULL)
		{
			if(pos==i)
			{
				printf("\nThe Elemen is %d",tmp->data);
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
		printf("\nEmty");
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

void sorting()
{
	node *tmp,*ctmp;
	int tmpp;
	tmp=start;
	while(tmp != NULL)
	{
		ctmp=tmp->next;
		while(ctmp != NULL)
		{
			if(tmp->data >ctmp->data)
			{
				tmpp=tmp->data;
				tmp->data=ctmp->data;
				ctmp->data=tmpp;
			}
			ctmp=ctmp->next;
		}
		tmp=tmp->next;
	}
}

int main(){
	int choice;
	while(1)
	{
		printf("\n1-->Create\n2-->display\n3-->seach\n4-->sorting\nEnter Your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
			    display();
				break;
			case 3:
			    search();
				break;
			case 4:
			    sorting();
				break;	
			default:
			    printf("\nWrong choice");			
		}
	}
	return 0;
}

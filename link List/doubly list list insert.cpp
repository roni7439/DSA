#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
	struct list *pre;
}*start=NULL;
typedef struct list node;
void create()
{
	node *newnode,*tmp;
	newnode=(node*)malloc(sizeof(node));
	newnode->next=NULL;
	newnode->pre=NULL;
	printf("\nEnter The Node Data: ");
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
		newnode->pre=tmp;
	}
}

void create_first(int x)
{
    node *newn;
    newn=(node*)malloc(sizeof(node));
    
    newn->next=NULL;
    newn->pre=NULL;
    newn->data=x;
    
    if(start==NULL)
    {
        start=newn;
    }
    else
    {
        newn->next=start;
        start->pre=newn;
        start=newn;
    }
}


void insertend() {
	node *newnode,*tmp;
	newnode=(node*)malloc(sizeof(node));
	newnode->next=NULL;
	newnode->pre=NULL;
	printf("\nEnter The New Node Data: ");
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
		newnode->pre=tmp;
	
}
}


void display()
{
	node *dis;
	dis=start;
	if(dis == NULL)
	{
		printf("\nThe list is empty");
		exit(1);
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


	int main(){
	int choice;
	while(1)
	{
		printf("\n1-->create\n2-->insertfirts\n3-->insertend\n4-->insertany pos\n5-->Display\nEnter Your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
              int data1;
              printf("\nEnter The Data at First: ");
              scanf("%d",&data1);
              create_first(data1);
              break;
			case 3:
			    insertend();
				break;
		
			case 5:
			    display();
				break;
			default:
			    printf("\nWrong choice");					
		}
	}
	return 0;
}

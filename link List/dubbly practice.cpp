#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
	struct list *pre;
}*start=NULL;
typedef struct list node;
void create(int data)
{
	node *newnode,*temp;
	newnode=(node*)malloc(sizeof(node));
	newnode->next=newnode->pre=NULL;
	newnode->data=data;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		temp=start;
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->pre=temp;
	}
}
void display()
{
	node *dis;
	dis=start;
	if(dis==NULL)
	{
		printf("\nList Is empty");
	}
	else
	{
		printf("\nList Elemets are : ");
		while(dis != NULL)
		{
			printf("%d ",dis->data);
			dis=dis->next;
		}
	}
}
void insert_any_pos(int pos)
{
	node *newnode,*temp;
	newnode=(node*)malloc(sizeof(node));
	int data;
	printf("\nEnter Your data: ");
	scanf("%d",&data);
	newnode->next=newnode->pre=NULL;
	newnode->data=data;
	if(pos==1)
	{
		newnode->next=start;
		start->pre=newnode;
		start=newnode;
	}
	else
	{
		temp=start;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		newnode->next->pre=newnode;
		newnode->pre=temp;
		temp->next=newnode;
	}
	printf("\n%d is Inserted",data);
}
int delete_any_pos(int pos)
{
	node *temp,*ctemp;
	int val;
	if(pos==1)
	{
		temp=start;
		val=temp->data;
		start=temp->next;
		free(temp);
		temp=NULL;
	}
	else
	{
		temp=start;
		 for(int i=1;i<pos-1;i++)
		 {
		 	temp=temp->next;
		 }
		 val=temp->data;
		 temp->pre->next=temp->next;
		 temp->next->pre=temp->pre;
		 free(temp);
	}
	return val;
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->Create\n2-->display\n3-->Insert At any Position\n4-->Delete AT Any Position\nEnter Your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				int data;
				printf("\nEnter Your data: ");
				scanf("%d",&data);
				create(data);
				break;
			case 2:
			    display();
				break;
			case 3:
				int pos1;
				printf("\nEnter Your Position: ");
				scanf("%d",&pos1);
			    insert_any_pos(pos1);
				break;
			case 4:
			    int pos2;
				printf("\nEnter Your Position: ");
				scanf("%d",&pos2);
			    printf("\nDeleted Elemets is %d",delete_any_pos(pos2));
				break;
			default:
			    printf("\mWrong Choice...");			
		}
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct list
{
    struct list *pre;
    int data;
    struct list *next;
} *start=NULL;

typedef struct list node;

void create(int x)
{
    node *newnode,*tmp;
    newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->data=x;
    newnode->pre=NULL;
    
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

void create_atany_pos(int x,int y)
{
	node *newn,*tmp;
    newn=(node*)malloc(sizeof(node));
    
    newn->next=NULL;
    newn->pre=NULL;
    newn->data=x;
    
    
    tmp=start;
    for(int i=1;i<y-1;i++)
    {
    	tmp=tmp->next;
	}
	
	newn->next=tmp->next;
	newn->pre=tmp;
	tmp->next=newn;
	newn->next->pre=newn;
}


void create_last(int x)
{
	node *newn,*tmp;
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
		tmp=start;
		while(tmp->next != NULL)
		{
			tmp=tmp->next;
		}
		tmp->next=newn;
		newn->pre=tmp;
	}
	
}


int delete_first()
{
	int val;
	node *tmp;
	tmp=start;
	start=tmp->next;
	val=tmp->data;
	free(tmp);
	return val;
}

int delete_end()
{
	int val;
	node *tmp;
	tmp=start;
	while(tmp->next != NULL)
	{
		tmp=tmp->next;
	}
	val=tmp->data;
	tmp->pre->next=NULL;
	tmp->pre=NULL;
	free(tmp);
	return val;	
}

int delete_pos(int x)
{
	node *tmp;
	int val;
	tmp=start;
	for(int i=1;i<x;i++)
	{
		tmp=tmp->next;
	}
	val=tmp->data;
	tmp->pre->next=tmp->next;
	tmp->next->pre=tmp->pre;
	free(tmp);
	return val;
	
}

void display()
{
    node *dis;
    dis=start;
    
    if(dis == NULL)
    {
        printf("\nList Is Empty");
    }
    else
    {
        printf("\nList Eleents are: ");
        while(dis != NULL)
        {
            printf("%d\t",dis->data);
            dis=dis->next;
        }
    }
}

typedef struct list node;

int main()
{
    int choice;
    while(1)
    {
        printf("\n1-->Creat\n2-->Insert At First\n3-->Inser At Any Position\n4-->Insert At End\n5-->Delete At First\n6-->Delete AT End\n7-->Delete At Any POsition\n8-->Display\nEnter Your Choice: ");
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
              int data1;
              printf("\nEnter The Data at First: ");
              scanf("%d",&data1);
              create_first(data1);
              break;
            case 3:
              int data2,position;
              printf("\nEnter The Position: ");
              scanf("%d",&position);
              printf("\nEnter The Data at Any Position: ");
              scanf("%d",&data2);
              
              create_atany_pos(data2,position);
              break;
			  
			case 4:
              int data3;
              printf("\nEnter The Data at end: ");
              scanf("%d",&data3);
              create_last(data3);
              break;    
            case 5:
            	printf("\nDeleted Item is: %d",delete_first());
            	break;
            case 6:
            	printf("\nDeleted Item is: %d",delete_end());
            	break;
			case 7:
				int pos_del;
				printf("\nENter The POsition: ");
				scanf("%d",&pos_del);
            	printf("\nDeleted Item is: %d",delete_pos(pos_del));
            	break;		
            case 8:
              display();
              break;
            default:
              printf("\nWrong Choice...");
        }
    }
    return 0;
}

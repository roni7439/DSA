#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *next;
}*start=NULL;

typedef struct list node;

void create(int x)
{
	node *newnode,*tmp;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=x;
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

void insert_end(int y)
{
	node *newn,*tmp;
	newn=(node*)malloc(sizeof(node));
	newn->data=y;
	newn->next=NULL;
	
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
	}
}

void insert_first(int x)
{
	node *newf;
	newf=(node*)malloc(sizeof(node));
	newf->data=x;
	newf->next=NULL;
	
	if(start==NULL)
	{
		start=newf;
	}
	else
	{
		newf->next=start;
		start=newf;
	}
}

void insert_any_pos(int pos,int x)
{
	node *newi,*tmp;
	newi=(node*)malloc(sizeof(node));
	newi->data=x;
	newi->next=NULL;
	
	if(pos==1)
	{
		newi->next=start;
		start=newi;
	}
	else
	{
		tmp=start;
		for(int i=1;i<pos-1;i++)
		{
			tmp=tmp->next;
		}
		newi->next=tmp->next;
		tmp->next=newi;
		
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
	node *tmp,*pre;
	tmp=start;
	if(start->next == NULL)
	{
		val=start->data;
		free(start);
		return val;
	}
	else
	{
		while(tmp->next != NULL)
	{
		pre=tmp;
		tmp=tmp->next;
	}
	val=tmp->data;
	pre->next=NULL;
	free(tmp);
	return val;
	}
	
}

int delete_any_pos(int x)
{
	int value;
	node *tmp,*pre;
	tmp=start;
	for(int i=1;i<x;i++)
	{
		pre=tmp;
		tmp=tmp->next;
	}
	value=tmp->data;
	pre->next=tmp->next;
	free(tmp);
	return value;
	
}


void sorting()
{
    node *tmp, *tmp1;
    int tmp_value;
    tmp = start;
    while (tmp != NULL)
    {
        tmp1 = tmp->next;
        while (tmp1 != NULL)
        {
            if (tmp->data > tmp1->data)
            {
                tmp_value = tmp->data;
                tmp->data = tmp1->data;
                tmp1->data = tmp_value;
            }
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
}


void display()
{
	node *dis;
	dis=start;
	if(dis == NULL)
	{
		printf("\nEmpty List");
	}
	else
	{
		printf("\nList Elements are: ");
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
		printf("\n1-->create\n2-->Inser At End\n3-->Insert At first\n4-->Insert any Position\n5--.Delete At First\n6-->Delete At End\n7-->Delete At Any Position\n8-->Sorting The List\n9-->display\nEnter your choice: ");
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
				int value_end;
				printf("\nEnter The End Value: ");
				scanf("%d",&value_end);
			    insert_end(value_end);
				break;	
			case 3:
			    int value_first;
				printf("\nEnter The First Value: ");
				scanf("%d",&value_first);
			    insert_first(value_first);
				break;
			case 4:
			    int pos,x;
				printf("\nEnter The Insertion Position: ");
				scanf("%d",&pos);
				printf("\nEnter The New Value: ");
				scanf("%d",&x);
				insert_any_pos(pos,x);
				break;
			case 5:
				printf("\nDeleted Item is %d: ",delete_first());
				break;
			case 6:
				printf("\nDeleted Item is %d: ",delete_end());
			    break;
			case 7:
				int pos_dele;
				printf("\nEnter The Position: ");
				scanf("%d",&pos_dele);
			    printf("\nDeleted Item is %d: ",delete_any_pos(pos_dele));	
				break;
			case 8:
			    sorting();
				break;			    
			case 9:
			    display();
			    break;  
			default:
			    printf("Wrong choice");    
		}
	}
	return 0;
}

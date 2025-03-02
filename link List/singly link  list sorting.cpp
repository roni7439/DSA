#include<stdio.h>
#include<stdlib.h>
struct slist{
	int data;
	struct slist *next;
}*start=NULL;
typedef struct slist node;
void create()
{
	node *tmp,*tmp1;
	tmp=(node *)malloc(sizeof(node));
	tmp->next=NULL;
	printf("\nEnter The Node Data: ");
	scanf("%d",&tmp->data);
	
	if(start==NULL)
	{
		start=tmp;
	}
	else
	{
		tmp1=start;
		while(tmp1->next != NULL)
		{
			tmp1=tmp1->next;
		}
		tmp1->next=tmp;
	}
}

void sorting()
{
	node *ptr,*cptr;
	int tmp;
	ptr=start;
	while(ptr != NULL)
	{
		cptr=ptr->next;
		while(cptr != NULL)
		{
			if(ptr->data > cptr->data)
			{
				tmp=ptr->data;
				ptr->data=cptr->data;
				cptr->data=tmp;
			}
			cptr=cptr->next;
		}
		ptr=ptr->next;
	}
}

void search()
{
	node *tmp;
	int i=0;
	int pos;
	printf("\nEnter The Position");
	scanf("%d",&pos);
	tmp=start;
	if(tmp==NULL)
	{
		printf("\nEmpty The List");
	}
	else
	{
		while(tmp != NULL)
		{
				if(pos==i)
				{
					printf("\nThe Posionied value is %d\n",tmp->data);
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
		while(dis
		 != NULL)
		{
			printf("%d\t",dis->data);
			dis=dis->next;
		}
	}
}

int main()
{
	int choice;
	while(1){
		printf("\nCreate -> 1\nDisplay -> 2\nSorting -> 3\nSearching-> 4");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		if(choice==1)
		{
			create();
		}
		else if(choice==2)
		{
			display();
		}
		else if(choice== 3)
		{
			printf("\nSorting is Perfectly Done !");
			sorting();		
		}
		else if(choice==4)
		{
			search();
		}
		else{
			printf("\n--------Stop--------");
			break;
		}
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct slist{
	int data;
	struct slist *pre;
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
		tmp->pre=tmp1;
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
		printf("\nCreate -> 1\nDisplay -> 2\nExit -> 3\n");
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
		else{
			printf("\n--------Stop--------");
			break;
		}
	}
	return 0;
}

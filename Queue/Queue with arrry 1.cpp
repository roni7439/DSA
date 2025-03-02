#include<stdio.h>
#define MAX 4
int arr[MAX];
int font=-1,rare=-1;

void add()
{
	if(rare == MAX-1)
	{
		printf("\nThe Qunue is Overflow");
	}
	else
	{
		int data;
		printf("\nEnter The Data: ");
		scanf("%d",&data);
		if(font==-1)
		{
			font=rare=0;
		}
		else
		{
			rare++;
		}
		arr[rare]=data;
		printf("\nItem inserted");
	}
}

void delet()
{
	if(font==-1)
	{
		printf("\nqunue is Underflow");
		
	}
	else
	{
		printf("\nDeleted item is %d",arr[font]);
		if(font==rare)
		{
			font=rare=-1;
		}
		else
		{
			font++;
		}
	}
}

void display()
{
	if(font==-1)
	{
		printf("\nThe Quneu is Underflow");
	}
	else
	{
		printf("\nThe Quneu Elements are: ");
		for(int i=font;i<=rare;i++)
		{
			printf("%d\t",arr[i]);
		}
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\nAdd-->1\nDelete-->2\nDisplay-->3\nExit\nEnter Your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				add();
				break;
			case 2:
			    delet();
				break;
			case 3:
			    display();
				break;
			default:
			    printf("\nWrong choice");		
		}
	}
	return 0;
}

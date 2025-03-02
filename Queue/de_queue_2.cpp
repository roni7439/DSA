#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int arrey[SIZE];
int f=-1,r=-1;

void en_f()
{
	if(r>=SIZE-1)
	{
		printf("\nArrey is Full");
	}
	else
	{
		int data;
		printf("\nEnter Your Value: ");
		scanf("%d",&data);
		if(f==-1)
		{
			f=r=0;
		}
		else if(f==0)
		{
			f=SIZE-1;
		}
		else
		{
			f--;
		}
		arrey[f]=data;
	}
}

void en_r()
{
	if(r>=SIZE-1)
	{
		printf("\nArrey is Full");
	}
	else
	{
		int data;
		printf("\nEnter Your Value: ");
		scanf("%d",&data);
		if(f==-1)
		{
		
			f=r=0;
	    }
		else
		{
			f--;
		}
		arrey[f]=data;
	}
}


void display()
{
	if(f==-1)
	{
		printf("\nThe Arrey is Empty");
	}
	else
	{
		int i;
		i=f;
		while(1)
		{
			printf("%d\t",arrey[i]);
			if(i==r)
			{
				break;
			}
			i=(i+1)%SIZE;
		}
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n1-->En-F\n2-->EN-R\n3-->Display\nEnter Your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				en_f();
				break;
			case 2:
			    en_r();
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

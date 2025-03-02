//push oparation
#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack_arr[MAX];//Global declaration
int top=-1;
void push(int);
int main()
{
	push(1);
	push(2);
	push(10);
	push(20);
	push(15);
	return 0;
}
void push(int data)
{
	if(top==MAX-1)
	{
		printf("\nStack overFlow and cannot push %d",data);
		return;
	}
	else
	{
		top++;
		stack_arr[top]=data;
		printf("\nData %d push in the stack\n",data);
	}
	
}

#include<stdio.h>
int arr[]={7,8,15,30};
int search(int item)
{
	int size=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<size;i++)
	{
		if(arr[i]==item)
		{
			return i+1;
		}
	}
	return -1;
}
int main()
{
	int item;
	printf("\nEnter The Item: ");
	scanf("%d",&item);
	int result=search(item);
	if(result != -1)
	{
		printf("\nThe terget item ar %d position",result);
	}
	else
	{
		printf("\nTergetNot found");
	}
	return 0;
}

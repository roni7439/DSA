#include<stdio.h>
int search(int arr[],int size,int terget)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==terget)
		{
			return i+1;
		}
	}
	return -1;
}

int main()
{
	int arr[]={7,8,10,30,55,89};
	int size=sizeof(arr)/sizeof(arr[0]);
	int terget;
	printf("\nThe Terget Value is: ");
	scanf("%d",&terget);
	int result=search(arr,size,terget);
	if(result != -1)
	{
		printf("\nThe Terget value at the position at %d",result);
	}
	else
	{
		printf("\nThe Terget Value not Found");
	}
	return 0;
}

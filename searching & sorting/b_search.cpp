#include<stdio.h>
int arr[]={7,10,20,30,35,40};

int search(int item)
{
	int size=sizeof(arr)/sizeof(arr[0]);
	int l=0,h=size;
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(item<arr[mid])
		{
			h=mid-1;
		}
		else if(item>arr[mid])
		{
			l=mid+1;
		}
		else
		{
			return mid+1;
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
		printf("\nItem found at the posotion of %d",result);
	}
	else
	{
		printf("\nItem not found");
	}
	return 0;
}

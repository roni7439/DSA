#include<stdio.h>

void marge_sort(int arr[],int n)
{
	
}

void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[]={2,4,3,9,8,6,1,0};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	marge_sort(arr,size);
	printf("\nSorted List is: ");
	print(arr,size);
	return 0;
}

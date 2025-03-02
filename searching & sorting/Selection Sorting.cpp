#include<stdio.h>

void sorted_arr(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

void print_arr(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[]={7,9,1,4,6,20,89,90,55,35};
	int size=sizeof(arr)/sizeof(arr[0]);
	sorted_arr(arr,size);
	printf("\nSorted Arrey: ");
	print_arr(arr,size);
	return 0;
}

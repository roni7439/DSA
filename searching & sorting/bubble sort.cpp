#include<stdio.h>
void bubble_sort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				int tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
			}
		}
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
	int arr[]={3,9,1,0,7,6,5,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,size);
	printf("\nSorted Arrey: ");
	print_arr(arr,size);
	return 0;
}

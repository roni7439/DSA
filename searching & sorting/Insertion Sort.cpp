#include<stdio.h>
void insertion_sort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int tmp=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>tmp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=tmp;
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
	insertion_sort(arr,size);
	printf("\nSorted Arrey: ");
	print_arr(arr,size);
	return 0;
}

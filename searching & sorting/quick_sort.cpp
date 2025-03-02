#include<stdio.h>

void swapp(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int marge_div(int arr[],int p,int q)
{
	int x=arr[p];
	int i=p;
	for(int j=p+1;j<=q;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			swapp(&arr[i],&arr[j]);
		}
	}
	swapp(&arr[p],&arr[i]);
	return i;
}

void quick_sort(int arr[],int p,int q)
{
	if(p<q)
	{
		int m=marge_div(arr,p,q);
		quick_sort(arr,p,m-1);
		quick_sort(arr,m+1,q);
	}
}

void print(int arr[],int n)
{
	printf("\nThe Sorted arrey are: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[]={9,3,5,1,0,4,2,8};
	int size=sizeof(arr)/sizeof(arr[0]);
	int p=0,q=size-1;
	quick_sort(arr,p,q);
	print(arr,size);
	return 0;
}

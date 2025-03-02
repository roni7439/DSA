#include<stdio.h>

void marge(int arr[],int mid,int L,int R)
{
	int n1=mid-L+1;
	int n2=R-mid;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++)
	{
		left[i]=arr[L+i];
	}
	for(int j=0;j<n2;j++)
	{
		right[j]=arr[mid+1+j];
	}
	
	int i=0,j=0,k=L;
	while(i<n1 && j<n2)
	{
		if(left[i]<right[j])
		{
			arr[k]=left[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=right[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		arr[k]=left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=right[j];
		j++;
		k++;		
	}
}

void marge_sort(int arr[],int L,int R)
{
	int mid;
	if(L<R)
	{
		mid=(L+R)/2;
		marge_sort(arr,L,mid);
		marge_sort(arr,mid+1,R);
		marge(arr,mid,L,R);
	}
}

void print_arr(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
int main()
{
	int arr[]={7,2,1,0,5,4,9,3};
	int size=sizeof(arr)/sizeof(arr[0]);
	int low=0;
	int high=size-1;
	marge_sort(arr,low,high);
	print_arr(arr,size);
	return 0;
}

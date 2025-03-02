#include<stdio.h>

void marge(int arr[],int low,int mid,int high)
{
    int n1,n2;
    n1=mid-low+1;
    n2=high-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
    {
        left[i]=arr[low+i];
    }
    for(int j=0;j<n2;j++)
    {
        right[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
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

void marge_div(int arr[],int low,int high)
{
    int mid=(low+high)/2;
    if(low < high)
    {
        marge_div(arr,low,mid);
        marge_div(arr,mid+1,high);
        marge(arr,low,mid,high);
    }
}

void print(int arr[],int n)
{
    printf("\nSorted arrey are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[]={5,1,0,2,8,4,7,3};
    int low,high;
    int size=sizeof(arr)/sizeof(arr[0]);
    low=0;
    high=size-1;
    marge_div(arr,low,high);
    print(arr,size);
    return 0;
}

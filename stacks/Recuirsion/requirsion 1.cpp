#include<stdio.h>
void display(int);
int main()
{
    int n;
    printf("Enter The Number: ");
    scanf("%d",&n);
    
    display(n);
}

void display(int n)
{
    static int i=1;
    if(i>=n+1)
    {
        return;
    }
    printf("%d  ",i);
    i++;
    display(n);
}

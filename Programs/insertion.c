#include <stdio.h>
int main()
{
    int i,j,n,key;
    printf("enter the size of an array:");
    scanf("%d",&n);
    int a[n];
    printf("enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array before sorting:\n");
    for(i=0;i<n;i++)
    {
    printf("%d\t",a[i]);
    }
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("\nArray after sorting:\n ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
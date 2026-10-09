#include<stdio.h>
int main()
{
    int i,j,temp,n;
    printf("enter the size of an array: ");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of an array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array before sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nArray after sorting:\n");
    for(i=0;i<n;i++)
    {
      printf("%d\t",a[i]);
    }
    return 0;
}
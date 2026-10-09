#include<stdio.h>
int main()
{
    int high,low,i,n,key,found,mid;
    printf("enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements in ascending order: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element to be searched: ");
    scanf("%d",&key);
    low=0; high=n-1;
    while(low<=high)
    {
    mid=low+(high-low)/2;
    if(key==arr[mid])
    {
        found=1;
        break;
    }
    else if(key<arr[mid])
    {
        high=mid-1;
    }
    else 
    {
        low=mid+1;
    }
    }
    if(found==1)
        printf("the key is in the locaton :%d",mid+1);
    else
        printf("the value is not found.");

}

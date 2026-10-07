#include<stdio.h>
int main()
{
    int n,low,mid,high,i,empID;
    int found=0,count=0;
    printf("enter the number of employees:");
    scanf("%d",&n);
    int a[n];
    printf("enter the employee ID.s:");
    for(i=0;i<n;i++)
    {
     scanf("%d",&a[i]);
    }
    printf("enter the employe ID to search:");
    scanf("%d",&empID);
    low=0;high=n-1;
    while(low<=high)
    {
     mid=low+(high-low)/2;
     count++;
     if(empID==a[mid])
     {   
        found=1;
        break;
     }
     else if(empID < a[mid])
     {
        high=mid-1;
     }
     else
     {
       low=mid+1;
     }
    }
    if(found==1)
    {
      printf("Employee id is found at position:%d",mid+1);
    }
    else
    {
      printf("employee Id not found");
    }
    printf("\nNumber of comparisions:%d",count);
    return 0;
}

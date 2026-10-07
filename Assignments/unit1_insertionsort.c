#include<stdio.h>
int main()
{
    int n,i,j,key,shiftcount=0;
    printf("enter the no.of marks:");
    scanf("%d",&n);
    int marks[n];
    printf("enter the marks:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&marks[i]);
    }
    for(i=1;i<n;i++)
    {
        key=marks[i];
        j=i-1;
        while(j>=0 && marks[j]>key)
        {
            marks[j+1]=marks[j];
            j--;
            shiftcount++;
        }
        marks[j+1]=key;
        printf("After pass %d:",i);
        for(j=0;j<n;j++)
        {
        printf("%d ",marks[j]);
        }
        printf("\n");
    }
    printf("final array:");
    for(i=0;i<n;i++)
    {
    printf("%d ",marks[i]);
    }
    printf("\n");
    printf("total shift count:%d",shiftcount);
}
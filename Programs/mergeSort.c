#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int c[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    /* Compare elements from both halves */
    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = a[j];
            j++;
        }
        k++;
    }

    /* Copy remaining elements from left hand side */
    while(i <= mid)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    /* Copy remaining elements from right hand side */
    while(j <= high)
    {
        c[k] = a[j];
        j++;
        k++;
    }

    /* Copy sorted elements back to original array */
    for(i = low; i <= high; i++)
    {
        a[i] = c[i];
    }
}

/* Recursive merge sort function */
void mergesort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("Sorted array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

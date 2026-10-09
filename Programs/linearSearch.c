#include <stdio.h>

int main()
{
    int n, i, key, found = 0;

    printf("Enter the array size: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            found = 1;
            break;
        }
    }

    if(found == 1)
        printf("Key found at location %d\n", i + 1);
    else
        printf("Key is not found\n");

    return 0;
}

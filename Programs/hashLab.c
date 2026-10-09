#include <stdio.h>

int main()
{
    int n, k, i, key, loc;
    
    printf("Enter the size of array (n): ");
    scanf("%d", &n);

    printf("Enter number of keys (k): ");
    scanf("%d", &k);

    int hash_table[n];

    for(i = 0; i < n; i++)
        hash_table[i] = -1;

   for(i = 0; i < k; i++)
    {
        printf("Enter key: ");
        scanf("%d", &key);

        loc = key % n;

        if(hash_table[loc] == -1)
        {
            hash_table[loc] = key;
        }
        else
        {
            printf("Collision occurred for key %d\n", key);
        }
    }

    printf("\nHash Table:\n");
    for(i = 0; i < n; i++)
    {
        printf("hash[%d] = %d\n", i, hash_table[i]);
    }

    return 0;
}

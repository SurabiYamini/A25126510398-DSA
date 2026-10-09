#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5

int h[TABLE_SIZE];

void insert()
{
    int key, index, i, hkey;

    printf("\nEnter a value to insert into hash table: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;

    for(i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i * i) % TABLE_SIZE;

        if(h[index] == -1)
        {
            h[index] = key;
            printf("Value inserted at index %d\n", index);
            break;
        }
    }

    if(i == TABLE_SIZE)
        printf("Element cannot be inserted\n");
}

void search()
{
    int key, index, i, hkey;

    printf("\nEnter search element: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;

    for(i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i * i) % TABLE_SIZE;

        if(h[index] == key)
        {
            printf("Value is found at index %d\n", index);
            return;
        }

        if(h[index] == -1)
            break;
    }

    printf("Value is not found\n");
}

void display()
{
    int i;

    printf("\nElements in the hash table are:\n");

    for(i = 0; i < TABLE_SIZE; i++)
    {
        printf("Index %d : %d\n", i, h[i]);
    }
}

int main()
{
    int choice, i;

    for(i = 0; i < TABLE_SIZE; i++)
        h[i] = -1;

    while(1)
    {
        printf("\n===== HASH TABLE =====\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

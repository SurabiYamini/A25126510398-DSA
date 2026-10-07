#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char page[50];
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node* createNode(char page[])
{
    struct node *newnode = malloc(sizeof(struct node));

    strcpy(newnode->page, page);
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}


void insertPage(char page[])
{
    struct node *newnode = createNode(page);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    printf("Page inserted successfully!!\n");
}

void moveForward(char page[])
{
    struct node *temp = head;

    while (temp != NULL && strcmp(temp->page, page) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Page not found!!\n");
        return;
    }

    if (temp->next == NULL)
    {
        printf("Already at the last page. Cannot move forward.\n");
    }
    else
    {
        printf("Moved forward to: %s\n", temp->next->page);
    }
}

void moveBackward(char page[])
{
    struct node *temp = head;

    while (temp != NULL && strcmp(temp->page, page) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Page not found!!\n");
        return;
    }

    if (temp->prev == NULL)
    {
        printf("Already at the first page. Cannot move backward.\n");
    }
    else
    {
        printf("Moved backward to: %s\n", temp->prev->page);
    }
}

void deletePage(char page[])
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("Page list is empty.\n");
        return;
    }

    while (temp != NULL && strcmp(temp->page, page) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Page not found!!\n");
        return;
    }

    if (temp == head)
    {
        head = temp->next;

        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
    }

    if (temp == tail)
    {
        tail = temp->prev;

        if (tail != NULL)
            tail->next = NULL;
    }
    else
    {
        temp->next->prev = temp->prev;
    }

    printf("Page %s is deleted.\n", temp->page);

    free(temp);
}


void displayForward()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Page list is empty.\n");
        return;
    }

    temp = head;

    printf("Pages from first to last:\n");

    while (temp != NULL)
    {
        printf("%s <-> ", temp->page);
        temp = temp->next;
    }

    printf("NULL\n");
}

void displayBackward()
{
    struct node *temp;

    if (tail == NULL)
    {
        printf("Page list is empty.\n");
        return;
    }

    temp = tail;

    printf("Pages from last to first:\n");

    while (temp != NULL)
    {
        printf("%s <-> ", temp->page);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main()
{
    int choice;
    char page[50];

    while (1)
    {
        printf("\n*** WEB PAGE HISTORY ***\n");
        printf("1. Insert new page\n");
        printf("2. Move forward\n");
        printf("3. Move backward\n");
        printf("4. Delete page\n");
        printf("5. Display first to last\n");
        printf("6. Display last to first\n");
        printf("7. Exit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter page name: ");
                scanf("%s", page);
                insertPage(page);
                break;

            case 2:
                printf("Enter current page: ");
                scanf("%s", page);
                moveForward(page);
                break;

            case 3:
                printf("Enter current page: ");
                scanf("%s", page);
                moveBackward(page);
                break;

            case 4:
                printf("Enter page to delete: ");
                scanf("%s", page);
                deletePage(page);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!!\n");
        }
    }

    return 0;
}
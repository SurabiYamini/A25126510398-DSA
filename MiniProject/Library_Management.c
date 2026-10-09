#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book
{
    int id;
    char title[50];
    char author[50];
    int available;
    struct Book *left;
    struct Book *right;
};
/* Create a new book */
struct Book* createBook(int id, char title[], char author[])
{
    struct Book *newBook;
    newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->available = 1;
    newBook->left = NULL;
    newBook->right = NULL;
    return newBook;
}
/* Insert a book */
struct Book* insert(struct Book *root, int id, char title[], char author[])
{
    if (root == NULL)
    {
        return createBook(id, title, author);
    }
    if (id < root->id)
    {
        root->left = insert(root->left, id, title, author);
    }
    else if (id > root->id)
    {
        root->right = insert(root->right, id, title, author);
    }
    else
    {
        printf("Book ID already exists!\n");
    }
    return root;
}
/* Search a book */
struct Book* search(struct Book *root, int id)
{
    if (root == NULL || root->id == id)
    {
        return root;
    }
    if (id < root->id)
    {
        return search(root->left, id);
    }
    return search(root->right, id);
}
/* Find minimum node */
struct Book* findMin(struct Book *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
/* Delete a book */
struct Book* deleteBook(struct Book *root, int id)
{
    struct Book *temp;

    if (root == NULL)
    {
        return NULL;
    }
    if (id < root->id)
    {
        root->left = deleteBook(root->left, id);
    }
    else if (id > root->id)
    {
        root->right = deleteBook(root->right, id);
    }
    else
    {
        /* No left child */
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        /* No right child */
        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        /* Two children */
        temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->title, temp->title);
        strcpy(root->author, temp->author);
        root->available = temp->available;
        root->right = deleteBook(root->right, temp->id);
    }
    return root;
}
/* Display books in sorted order */
void display(struct Book *root)
{
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    printf("\n----------------------------");
    printf("\nBook ID   : %d", root->id);
    printf("\nTitle     : %s", root->title);
    printf("\nAuthor    : %s", root->author);
    if (root->available == 1)
        printf("\nStatus    : Available\n");
    else
        printf("\nStatus    : Issued\n");
    printf("\n----------------------------\n");
    display(root->right);
}
/* Issue a book */
void issueBook(struct Book *root, int id)
{
    struct Book *book = search(root, id);
    if (book == NULL)
    {
        printf("Book not found!\n");
    }
    else if (book->available == 0)
    {
        printf("Book is already issued!\n");
    }
    else
    {
        book->available = 0;
        printf("Book issued successfully!\n");
    }
}
/* Return a book */
void returnBook(struct Book *root, int id)
{
    struct Book *book = search(root, id);
    if (book == NULL)
    {
        printf("Book not found!\n");
    }
    else if (book->available == 1)
    {
        printf("Book is already available!\n");
    }
    else
    {
        book->available = 1;
        printf("Book returned successfully!\n");
    }
}
/* Main function */
int main()
{
    struct Book *root = NULL;

    int choice;
    int id;
    char title[50];
    char author[50];
    do
    {
        printf("\n====================================\n");
        printf("     LIBRARY MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Delete Book\n");
        printf("4. Display Books\n");
        printf("5. Issue Book\n");
        printf("6. Return Book\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                printf("Enter Book Title: ");
                scanf(" %[^\n]", title);
                printf("Enter Author Name: ");
                scanf(" %[^\n]", author);
                root = insert(root, id, title, author);
                printf("Book added successfully!\n");
                break;
            case 2:
            {
                struct Book *book;
                printf("Enter Book ID: ");
                scanf("%d", &id);
                book = search(root, id);
                if (book == NULL)
                {
                    printf("Book not found!\n");
                }
                else
                {
                    printf("\nBook Found!\n");
                    printf("ID     : %d\n", book->id);
                    printf("Title  : %s\n", book->title);
                    printf("Author : %s\n", book->author);
                    if (book->available)
                        printf("Status : Available\n");
                    else
                        printf("Status : Issued\n");
                }
                break;
            }
            case 3:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                if (search(root, id) == NULL)
                {
                    printf("Book not found!\n");
                }
                else
                {
                    root = deleteBook(root, id);
                    printf("Book deleted successfully!\n");
                }
                break;
            case 4:
                printf("\n===== ALL BOOKS =====\n");
                if (root == NULL)
                {
                    printf("No books in library!\n");
                }
                else
                {
                    display(root);
                }
                break;
            case 5:
                printf("Enter Book ID to issue: ");
                scanf("%d", &id);
                issueBook(root, id);
                break;
            case 6:
                printf("Enter Book ID to return: ");
                scanf("%d", &id);
                returnBook(root, id);
                break;
            case 7:
                printf("Thank you!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);
    return 0;
}
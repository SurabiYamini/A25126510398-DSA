/*
Extend a Binary Search Tree program to support deletion. The program should create
a BST, delete a user-specified node, correctly handle the case where the node has
zero, one and two children, and display inorder traversal before and after deletion.
Test the program separately for all three deletion cases.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* insert(struct Node *root,int data)
{
    if(root==NULL)
        return createNode(data);
    if(data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    return root;
}
struct Node* Minvaluefind(struct Node *root)
{
    struct Node *temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
}
struct Node* deleteNode(struct Node *root,int key)
{
    struct Node *temp;
    if(root==NULL)
        return root;
    if(key<root->data)
        root->left=deleteNode(root->left,key);
    else if(key>root->data)
        root->right=deleteNode(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        temp=Minvaluefind(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main()
{
    struct Node *root=NULL;
    int n,value,key,i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter values:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        root=insert(root,value);
    }
    printf("Inorder before deletion: ");
    inorder(root);
    printf("\nEnter value to delete: ");
    scanf("%d",&key);
    root=deleteNode(root,key);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}

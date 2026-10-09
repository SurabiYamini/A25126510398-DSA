/*
A system stores unique integer identification numbers using a Binary Search Tree.
Write a C program to insert values, display inorder, preorder and postorder traversals,
search for a specified value, and report whether it exists. Use the output to explain
why inorder traversal produces sorted values.
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
void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct Node* search(struct Node *root,int key)
{
    if(root==NULL||root->data==key)
        return root;
    if(key<root->data)
        return search(root->left,key);
    return search(root->right,key);
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
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nEnter value to search: ");
    scanf("%d",&key);
    if(search(root,key)!=NULL)
        printf("Value %d exists in BST.\n",key);
    else
        printf("Value %d does not exist in BST.\n",key);
    printf("Inorder traversal gives sorted values because BST stores smaller values in the left subtree and larger values in the right subtree.\n");
    return 0;
}

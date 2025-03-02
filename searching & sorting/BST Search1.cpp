// BST Searching Programm
#include <stdio.h>
#include<stdlib.h>
struct list
{
    int data;
    struct list *left,*right;
};
typedef struct list node;

node* create(int data)
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* insert(node *root,int data)
{
    if(root == NULL)
    {
        root=create(data);
    }
    else if(data < root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

node* search(node *root,int value)
{
    if(root==NULL || root->data==value)
    {
        return root;
    }
    else if(value < root->data)
    {
        return search(root->left,value);
    }
    else
    {
        return search(root->right,value);
    }
}

int main() {
    int choice;
    int data;
    node *root=NULL;
    while(1)
    {
        printf("\n1-->Insert\n2-->Inorder\n3-->Preorder\n4-->Postorder\n5-->search\nEnter Your choice: ");
        
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
              printf("\nEnter The data: ");
              scanf("%d",&data);
              root=insert(root,data);
              break;
            case 2:
              printf("\nInorder List: ");
              inorder(root);
              break;
            case 3:
              printf("\nPreorder List: ");
              preorder(root);
              break;
            case 4:
              printf("\nPostorder List: ");
              postorder(root);
              break;
            case 5:
              int value;
              printf("\nEnter The Value That to be searched: ");
              scanf("%d",&value);
              if(search(root,value))
              {
                  printf("\nThe searching data found in the tree");
              }
              else
              {
                  printf("\nNot found in The Tree");
              }
              break;
            default:
              printf("\nWrong choice--");
        }
    }
    
    return 0;
}

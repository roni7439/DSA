//BST Inserting

#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *left,*right;
};
typedef struct list node;

node* create(int value)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->left=newnode->right=NULL;
	
	return newnode;
}

void preorder(node* root)
{
	if(root != NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(node* root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

node* insert(node* root,int value)
{
	if(root == NULL)
	{
		root=create(value);
	}
	else if(value < root->data)
	{
		root->left=insert(root->left,value);
	}
	else
	{
		root->right=insert(root->right,value);
	}
	
	return root;
}
int main()
{
	int choice;
	int value;
	node *root=NULL;
	while(1)
	{
		printf("\n1-->Insert The Data: \n2-->preOrder: \n3-->Inorder: \n4-->postorde: \nEnter Your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter The value: ");
				scanf("%d",&value);
				root=insert(root,value);
				break;
			case 2:
			    printf("\nPre Order: ");
				preorder(root);
				break;
			case 3:
			    printf("\nIn_Order: ");
				inorder(root);
				break;
			case 4:
			    printf("\npostOrder: ");
				postorder(root);
				break;		
			default:
			    printf("\nWrong choice");		
		}
	}
	return 0;
}

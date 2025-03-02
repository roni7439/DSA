#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *left,*right;
};

typedef struct list node;

void preorder(node *root)
{
	if(root != NULL)
	{
		preorder(root->left);
		printf("%d ",root->data);
		preorder(root->right);
	}
}

void inorder(node *root)
{
	if(root != NULL)
	{
		printf("%d ",root->data);
		inorder(root->left);
		inorder(root->right);
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

node* create(int data)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

node* Tree()
{
	node *root;
	root=create(8);
	root->left=create(9);
	root->right=create(5);
	root->right->left=create(7);
	root->right->right=create(6);
	return root;
}
int main()
{
	node *Root;
	Root=Tree();
	printf("\nPre_Order: ");
	preorder(Root);
	printf("\nIn-Order: ");
	inorder(Root);
	printf("\nPost-Order: ");
	postorder(Root);
	return 0;
}

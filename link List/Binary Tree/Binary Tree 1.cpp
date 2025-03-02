//Binary Tree Traversal(Pre_Order,Post-Order,In-Order)

#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left,*right;
};

typedef struct tree node; 

node* create(int data)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	
	return newnode;
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


node* createTree()
{
	node *root;
	root=create(4);
	root->left=create(5);
	root->right=create(7);
	root->left->left=create(8);
	root->left->right=create(10);
	root->right->left=create(12);
	root->right->right=create(9);
	
	return root;
}

int main()
{
	node *root=createTree();
	
	printf("\nInOrder Tree: ");
	inorder(root);
	printf("\nPreOrder Tree: ");
	preorder(root);
	printf("\nPostOrder Tree: ");
	inorder(root);
	return 0;
}

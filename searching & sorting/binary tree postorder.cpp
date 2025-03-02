#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *left,*right;
};

typedef struct list node;

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

node* tree()
{
	node *root;
	root=create(8);
	root->left=create(7);
	root->left->left=create(5);
	root->left->right=create(6);
	root->right=create(9);
	root->right->right=create(1);
	root->right->left=create(3);
	root->right->left->left=create(2);
	
	return root;
}

int main()
{
	node *root;
	root=tree();
	printf("\npost-order: ");
	postorder(root);
	return 0;
}

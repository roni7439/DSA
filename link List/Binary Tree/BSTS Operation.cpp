#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left,*right;
};

typedef struct tree node;

node* create(int value)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->left=newnode->right=NULL;
	
	return newnode;
}

node* insert(node *root,int value)
{
	if(root == NULL)
	{
		return create(value);
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

void inorder(node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

node* search(node* root,int data)
{
	if(root == NULL || root->data==data)
	{
		return root;
	}
	else if(data < root->data)
	{
		return search(root->left,data);
	}
	else
	{
		return search(root->right,data);
	}
}

int main()
{
	node *root=NULL;
	int choice,value;
	while(1)
	{
		printf("\n1-->Insert Node\n2-->Inorder Display\n3-->Searching Node\nEnter The Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter The Value: ");
				scanf("%d",&value);
				root=insert(root,value);
				break;
			case 2:
			    inorder(root);
				break;
			case 3:
			    int data;
				printf("\nEnter The Search Data: ");
				scanf("%d",&data);
				if(search(root,data))
				{
					printf("\nData Found in The Tree");
				}
				else
				{
					printf("\nData Not found");
				}
				break;
			default:
			    printf("\nEnter Right choice");			
		}
	}
	return 0;
}

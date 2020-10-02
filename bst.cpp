#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d ", root->key); 
		inorder(root->right); 
	} 
} 
struct node* insert(struct node* node, int key) 
{ 
	
	if (node == NULL) 
	return newNode(key);
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key >= node->key) 
		node->right = insert(node->right, key); 
	return node; 
} 
int main() 
{ 
	struct node *root = NULL; 
	printf("Enter the value of n\n");
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the values to be inserted\n");
		int k;
		scanf("%d",&k);
		if(i==0)
		{
			root = insert(root,k);
			printf("Inorder traversal will be\n");
			inorder(root);
		}
		else
		{
			insert(root,k);
			printf("Inorder traversal will be\n");
			inorder(root);
		}
	}
	return 0;
}



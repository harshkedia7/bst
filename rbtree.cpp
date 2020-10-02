#include <stdio.h>
#include <stdlib.h>
struct node {
 int data, color;
 struct node *link[2];
};
enum nodeColor {
 RED,BLACK
};
struct node *root = NULL;
struct node *createNode(int data) {
 struct node *newnode;
 newnode = (struct node *)malloc(sizeof(struct node));
 newnode->data = data;
 newnode->color = RED;
 newnode->link[0] = newnode->link[1] = NULL;
 return newnode;
}
void insertion(int data) {
 struct node *s[98], *ptr, *newnode, *xPtr, *yPtr;
 int dir[98], ht = 0, index;
 ptr = root;
 if (!root) {
 root = createNode(data);
 return;
 }
 s[ht] = root;
 dir[ht++] = 0;
 while (ptr != NULL) {
 index = (data - ptr->data) > 0 ? 1 : 0;
 s[ht] = ptr;
 ptr = ptr->link[index];
 dir[ht++] = index;
 }
 s[ht - 1]->link[index] = newnode = createNode(data);
 while ((ht >= 3) && (s[ht - 1]->color == RED)) {
 if (dir[ht - 2] == 0) {
 yPtr = s[ht - 2]->link[1];
 if (yPtr != NULL && yPtr->color == RED) {
 s[ht - 2]->color = RED;
 s[ht - 1]->color = yPtr->color = BLACK;
 ht = ht - 2;
 } else {
 if (dir[ht - 1] == 0) {
 yPtr = s[ht - 1];
 } else {
 xPtr = s[ht - 1];
 yPtr = xPtr->link[1];
 xPtr->link[1] = yPtr->link[0];
 yPtr->link[0] = xPtr;
 s[ht - 2]->link[0] = yPtr;
 }
 xPtr = s[ht - 2];
 xPtr->color = RED;
 yPtr->color = BLACK;
 xPtr->link[0] = yPtr->link[1];
 yPtr->link[1] = xPtr;
 if (xPtr == root) {
 root = yPtr;
 } else {
 s[ht - 3]->link[dir[ht - 3]] = yPtr;
 }
 break;
 }
 } else {
 yPtr = s[ht - 2]->link[0];
 if ((yPtr != NULL) && (yPtr->color == RED)) {
 s[ht - 2]->color = RED;
 s[ht - 1]->color = yPtr->color = BLACK;
 ht = ht - 2;
 } else {
 if (dir[ht - 1] == 1) {
 yPtr = s[ht - 1];
 } else {
 xPtr = s[ht - 1];
 yPtr = xPtr->link[0];
 xPtr->link[0] = yPtr->link[1];
 yPtr->link[1] = xPtr;
 s[ht - 2]->link[1] = yPtr;
 }
 xPtr = s[ht - 2];
 yPtr->color = BLACK;
 xPtr->color = RED;
 xPtr->link[1] = yPtr->link[0];
 yPtr->link[0] = xPtr;
 if (xPtr == root) {
 root = yPtr;
 } else {
 s[ht - 3]->link[dir[ht - 3]] = yPtr;
 }
 break;
 }
 }
 }
 root->color = BLACK;
}
void inorder(struct node *node) {
 if (node) {
 inorder(node->link[0]);
 printf("%d ", node->data);
 inorder(node->link[1]);
 }
 return;
}
// Driver code
int main()
{
 int ch, data;
 printf("Enter the number of nodes to be inserted\n");
 int n;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
	printf("\nEnter the value to be inserted\n");
	int k;
	scanf("%d",&k);
	insertion(k);
	printf("Inorder traversal will be\n");
	inorder(root);
 }
 return 0;
}


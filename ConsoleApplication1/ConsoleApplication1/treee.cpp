#include "tree.h"
#include "stdafx.h"
struct node{
	int info;
	struct node *left;
	struct node *right;
};

int count = 0;

struct node* insert(struct node *root, int value) {
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info = value;
	if (root == NULL) {
		newnode->left = newnode->right = NULL;
		root = newnode;
		count++;
	}
	else {
		if (count % 2 != 0)
			root->left = insert(root->left, value);
		else
			root->right = insert(root->right, value);
		}
	return root;
}
void display(struct node *root) {
	if (root!= NULL) {
		display(root->left);
		printf("%d\t", root->info);
		display(root->right);
	}



}
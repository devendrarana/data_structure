#include "stdafx.h"
#include "BinaryTree.h"
struct node *root = NULL;
void binarytree(){
	
	int choice,value,h;
	while (1) {
		printf("entre 1 for insertion\n");
		printf("entre 2 for dispaly\n");
		printf("entre 3 for height\n");
		printf("entre 4 for exit\n");
		printf("entre your choice\n");
	
		scanf("%d", &choice);
		switch (choice) {
		case 1: printf("entre the value");
			scanf("%d", &value);
			root=insert(value,root);
			break;
		case 2:
			inorderdisplay(root);
			break;
		case 3:h= getHeight(root);
			printf("Height of the tree is %d", h);
			break;
		case 4: exit(1);
		default:
			printf("wrong choice");
	}
	}


}

int getHeight(struct node* node ) {

	if (node == NULL) {
		return 0;
	}

	int leftTreeHeight = getHeight(node->left);
	int rightTreeHeight = getHeight(node->right);

	return leftTreeHeight > rightTreeHeight ? leftTreeHeight + 1 : rightTreeHeight + 1;


}

struct node* insert(int d,struct node *root)
{
	struct node *p,*t = (struct node *)malloc(sizeof(struct node));
	t->data = d;
	t ->left = NULL;
	t -> right = NULL;
	p = root;
	if (root == NULL) {
		root = t;
		return root;
	}
	else {
		struct node *curr = root;
		struct node *parent=NULL;
		while (curr) {
			parent = curr;
			if (t->data > curr->data) {
				curr = curr->right;
			}
			else {
				curr = curr->left;
			}
		}
		
			if (t->data > parent->data) {
				parent->right = t;
			}
			else {
				parent->left = t;
			}


		
		return root;
	}
}
void inorderdisplay(struct node *t) {
	if (t->left)
		inorderdisplay(t->left);
	printf("%d ", t->data);
	if (t->right)
		inorderdisplay(t->right);
	

}
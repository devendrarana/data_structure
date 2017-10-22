#include "stdafx.h"
#include "tree.h"

int count = 0;

void tree::showTreeOptions() {
	int choice, value;
	struct tree::node *root = NULL;
	while (1) {
		printf("1 insert\n 2 display\n 3 exit");
		printf("entre your choice");
		scanf("%d", &choice);
		switch (choice) {
		case 1:printf("entre the value to be inserted");
			scanf("%d", &value);
			root = tree::insert(root, value);
			break;
		case 2:tree::display(root);
			break;
		case 3:exit(0);
		default:
			printf("wrong choice");
		}
	}
}

struct tree::node* tree::insert(struct tree::node* root, int value) {
	struct tree::node *newnode = (struct tree::node*)malloc(sizeof(struct tree::node));
	newnode->info = value;
	if (root == NULL) {
		newnode->left = newnode->right = NULL;
		root = newnode;
		count++;
	}
	else {
		if (count % 2 != 0)
			root->left = tree::insert(root->left, value);
		else
			root->right = tree::insert(root->right, value);
	}
	return root;
}
void tree::display(struct tree::node *root) {
	if (root != NULL) {
		tree::display(root->left);
		printf("%d\t", root->info);
		tree::display(root->right);
	}
}
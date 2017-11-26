#include "stdafx.h"
#include "BinaryTree.h"
#include <queue>
#define MAX 1500
struct node *root = NULL;
void binarytree() {

	int choice, value, h;
	while (1) {
		printf("entre 1 for insertion\n");
		printf("entre 2 for dispaly\n");
		printf("entre 3 for height\n");
		printf("entre 4 for tree level display\n");
		printf("entre 5 for level display");
		printf("enter 6 for exit\n");
		printf("entre 7 for level traversal");
		printf("entre your choice\n");

		scanf("%d", &choice);
		switch (choice) {
		case 1: printf("entre the value");
			scanf("%d", &value);
			root = insert(value, root);
			break;
		case 2:
			inorderdisplay(root);
			break;
		case 3:h = getHeight(root);
			printf("Height of the tree is %d", h);
			break;
		case 4: TreeLevelDisplay(root);
			break;
		case 5:leveldisplay(root);
			break;
		case 6:exit(1);

			break;
		case 7:leveltraversal(root);
			break;
		default:
			printf("wrong choice");
		}
	}


}

int getHeight(struct node* node) {

	if (node == NULL) {
		return 0;
	}

	int leftTreeHeight = getHeight(node->left);
	int rightTreeHeight = getHeight(node->right);

	return leftTreeHeight > rightTreeHeight ? leftTreeHeight + 1 : rightTreeHeight + 1;


}

struct node* insert(int d, struct node *root)
{
	struct node *p, *t = (struct node *)malloc(sizeof(struct node));
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	p = root;
	if (root == NULL) {
		root = t;
		return root;
	}
	else {
		struct node *curr = root;
		struct node *parent = NULL;
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
	printf("%d", t->data);

	if (t->right)
		inorderdisplay(t->right);
}

void TreeLevelDisplay(struct node* t) {
	std::queue<struct node*> q1;
	int level = 0;
	q1.push(t);
	innerDisplay(q1, t, level);

}

void innerDisplay(std::queue<struct node*> q, struct node* t, int level) {
	if (q.size() == 0) return;

	int height = getHeight(t);
	int numberOfTabsForCurrentLevel = height - level;

	printTabs(numberOfTabsForCurrentLevel);
	int numberOfNodesInQueue = q.size();

	while (numberOfNodesInQueue-- > 0) {
		//  pop from queue and print
		struct node* t = q.front(); q.pop();
		printf("%d \t", t->data);
		if (t->left != NULL) {
			q.push(t->left);
		}
		if (t->right != NULL) {
			q.push(t->right);
		}
	}

	innerDisplay(q, t, level + 1);

}

void printTabs(int count) {
	printf("\n");
	while (count-- > 0) {
		printf("\t");
	}
}
void leveldisplay(struct node *root) {

	printf("\t\t %d\n\n",root->data);
	if(root->left)
		printf("%d\t\t\t\t", root->left->data);
	if(root->right)
		printf("%d\n", root->right->data);
	printf("\n");
	leveldisplay(root->left);
	
	leveldisplay(root->right);
}
struct node *nodeQueue[MAX];
int front = -1, rear = -1;
void insertQueue(struct node *item) {
	if (rear == MAX - 1) {
		printf("overflow");

	}
	if (front == -1)
		front = 0;
	rear = rear + 1;
	nodeQueue[rear] = item;
}
struct node *deleteQueue() {

	struct node *item;
	if (front == -1 || front == rear + 1) {
		printf("underflow");
		return NULL;
	}
	item = nodeQueue[front];
	front = front + 1;
	return item;

}
int queueempty() {
	if (front ==-1 || front == rear + 1)
		return 1;
	else
		return 0;

}
void leveltraversal(struct node *root) {
	struct node *ptr = root;
	if (ptr== NULL) {

		printf("tree is empty");
		printf("\n");
		return;
	}
	insertQueue(ptr);

	while (!queueempty()) {
		ptr = deleteQueue();
		printf("%d", ptr->data);
		if (ptr->left != NULL) {
			insertQueue(ptr->left);

		}
		if (ptr->right != NULL) {
			insertQueue(ptr->right);
		}
		printf("\n");
	}
}
#pragma once
#include "stdafx.h"
#include "stdlib.h"
#include <queue>

using namespace std;
struct node {
	int data;
	struct node *left;
	struct node *right;
};
void binarytree();
struct node * insert(int d,struct node *root);
void inorderdisplay(struct node *t);
int getHeight(struct node* node);
void TreeLevelDisplay(struct node* t);
void innerDisplay(queue<struct node*> q,struct node* t, int level);

void printTabs(int count);
void leveldisplay(struct node* root);
void leveltraversal(struct node *root);
void insertQueue(struct node *item);
int deleteQueue();
int queueempty();
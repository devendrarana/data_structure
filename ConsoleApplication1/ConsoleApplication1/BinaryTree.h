#pragma once
#include "stdafx.h"
#include "stdlib.h"
struct node {
	int data;
	struct node *left;
	struct node *right;
};
void binarytree();
struct node * insert(int d,struct node *root);
void inorderdisplay(struct node *t);
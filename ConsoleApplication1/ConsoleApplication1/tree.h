#pragma once
#include "stdafx.h"
#include <stdlib.h>

namespace tree
{
	struct node {
		int info;
		struct node *left;
		struct node *right;
	};
	void display(struct node *);
	struct node* insert(struct node *root, int value);
	void showTreeOptions();
}
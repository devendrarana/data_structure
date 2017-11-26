#pragma once
#include"stdafx.h"
struct node *insert_left_check(struct node*pptr, int *ptaller);
struct node* rotateright(struct node *pptr);
struct node* rotateleft(struct node *pptr);
struct node *insert(struct node *pptr, int ikey);
struct node *insert_leftbalance(struct node *pptr);
struct node *insert_right_check(struct node*pptr, int *ptaller);

struct node *insert_rightbalance(struct node *pptr);
void avlTree();
void inorder(struct node *root);
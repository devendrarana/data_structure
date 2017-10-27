#pragma once
#include<stdlib.h>
struct cnode {
	int info;
	struct cnode *link;

};
struct cnode* insertAtBeginning(struct cnode *last, int value);
struct cnode* insertAtEnd(struct cnode*last,int value);
struct cnode* insertAtAfter(struct cnode *last,int value,int item);
struct cnode* deleteBeginning(struct cnode*,int value);
void display(struct cnode *last);
void circularlinked();
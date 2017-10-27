#include "stdafx.h"
#include "doublelinked.h"

struct dnode {
	int info;
	struct dnode *left;
	struct dnode *right;

}; struct dnode *head = NULL;
void doublelinked() {
	int choice,value;
	while (1) {
		printf(" 1.insertion\n");
		printf(" 2.deletion\n");
		printf(" 3.display\n");
		printf(" 4.exit\n");
		printf(" entre your choice\n");
		scanf(" %d", &choice);
		switch (choice) {
		case 1: printf("enter the value\n");
			scanf("%d", &value);
			insert(value);
			break;
		case 2:printf("entre the value for deltion\n");
			scanf("%d", &value);
			deletion(value);
			break;
		case 3:display(head);
			break;
	
		case 4:exit(1);
		default:
			printf("wrong choice");
		}
	}

}
struct dnode*insert(int value) {
	struct dnode* tmp = (struct dnode*)malloc(sizeof(struct dnode));
	tmp->info = value;
	if (head == NULL) {
		tmp->left = NULL;
		tmp->right = NULL;
		head = tmp;
		return head;
	}
	else {
		struct dnode *t;
		t = head;
		while (t->right!= NULL)
		{
			t = t->right;
		}
		
		tmp->left = t;
		t->right = tmp;

		return head;

	}

}
struct dnode *deletion(int value) {
	struct dnode *t,*p;
	t = head;
	while (t->info != value)
	{
		t = t->right;
	}struct dnode *w = t;
	p = t->right;
	p->left = t->left;
	t= p;
	free(w);
	return head;
}
void display(struct dnode *head) {
	struct dnode*t=head;
	while (t->right != NULL)
		printf("%d ", t->info);
		t = t->right;
	


}
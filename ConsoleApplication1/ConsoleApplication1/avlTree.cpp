#include "stdafx.h"
#include "avlTree.h"
#include<stdbool.h>
struct node {
	int info;
	struct node* left;
	struct node* right;
	int balance;
};
void avlTree() {
	int choice, key;
	struct node *root = NULL;
	while (1) {
		printf("1.insert\n");
		printf("2.inordertraversal\n");
		printf("3.quit\n");
		printf("entre your choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:printf("enter the key to be inserted\n");
			scanf("%d", &key);
			root = insert(root, key);
			break;
		case 2:inorder(root);
			break;
		case 3: exit(1);
		default:
			printf("wrong choice\n");
		}


	}
}





struct node* rotateright(struct node *pptr) {
	struct node* aptr;
	aptr = pptr->left;
	pptr->left = aptr->right;
	aptr->right = pptr;
	return aptr;


}
struct node* rotateleft(struct node *pptr) {
	struct node *aptr;
	aptr = pptr->right;
	pptr->right = aptr->left;
	aptr->left = pptr;
	return aptr;

}
struct node *insert(struct node *pptr, int ikey) {
	static int taller;
	if (pptr == NULL) {
		pptr = (struct node*)malloc(sizeof(struct node));
		pptr->info = ikey;
		pptr->left = NULL;
		pptr->right = NULL;
		pptr->balance = 0;
		taller = true;


	}
	else if (ikey < pptr->info) {
		pptr->left = insert(pptr->left, ikey);
		if (taller == true)
			pptr = insert_left_check(pptr, &taller);
	}

		else if (ikey > pptr->info) {
			pptr->right = insert(pptr->right, ikey);
			if (taller == true) {
				pptr = insert_right_check(pptr, &taller);
			}
		}
		else {
			printf("dublicate key");
			taller =false;
		}
		return pptr;
	}
	struct node *insert_left_check(struct node*pptr, int *ptaller) {
		switch (pptr->balance)
		{
		case 0:
			pptr->balance = 1;
			break;
		case -1:pptr->balance = 0;
			*ptaller = false;
			break;
		case 1:pptr = insert_leftbalance(pptr);
			*ptaller = false;
		}
		return pptr;
	}

	struct node *insert_leftbalance(struct node *pptr)
	{
		struct node *aptr, *bptr;
		aptr = pptr->left;
		if (aptr->balance == 1)
		{
			pptr->balance = 0;
			aptr->balance = 0;
			pptr = rotateright(pptr);

		}
		else
		{
			bptr = aptr->right;
			switch (bptr->balance)
			{
			case -1:pptr->balance = 0;
				aptr->balance = 1;
				break;
			case 1:pptr->balance = -1;
				aptr->balance = 0;
				break;
			case 0:
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			}
			bptr->balance = 0;
			pptr->left = rotateleft(aptr);
			pptr = rotateright(pptr);
		}
		return pptr;
	}
		struct node *insert_right_check(struct node*pptr, int *ptaller) {
			switch (pptr->balance)
			{
			case 0:
				pptr->balance = -1;
				break;
			case -1:pptr->balance = 0;
				*ptaller = false;
				break;
			case 1:pptr = insert_rightbalance(pptr);
				*ptaller = false;
			}
			return pptr;
		}

		struct node *insert_rightbalance(struct node *pptr)
		{
			struct node *aptr, *bptr;
			aptr = pptr->right;
			if (aptr->balance == -1)
			{
				pptr->balance = 0;
				aptr->balance = 0;
				pptr = rotateleft(pptr);

			}
			else
			{
				bptr = aptr->left;
				switch (bptr->balance)
				{
				case -1:pptr->balance = 1;
					aptr->balance = 0;
					break;
				case 1:pptr->balance = 0;
					aptr->balance = -1;
					break;
				case 0:
					pptr->balance = 0;
					aptr->balance = 0;
					break;
				}
				bptr->balance = 0;
				pptr->right = rotateright(aptr);
				pptr = rotateleft(pptr);
			}
			return pptr;
		}
		void inorder(struct node *root){
			if (root != NULL) {
				inorder(root->left);
				printf("%d\t", root->info);
				inorder(root->right);
			}
		}





		
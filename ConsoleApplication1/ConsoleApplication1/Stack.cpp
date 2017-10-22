#include "stdafx.h"
#include "stack.h"

struct stack::StackNide *top = NULL;

void stack::showStackOptions() {
	
		int choice;
		while (1) {
			printf("you have the following option\n");
			printf("entre 1 for push\n");
			printf("enter 2 for pop\n");
			printf("enter 3 for diplay(traverse)\n");
			printf("entre 4 for exit\n");
			printf("entre your choice");
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:stack::push();
				break;
			case 2:stack::pop();
				break;
			case 3:stack::display();
				break;
			case 4:exit(1);
			default:
				printf("wrong choice");
			}
		}
	}




void stack::push()
{
	struct stack::StackNide *tmp = (struct stack::StackNide*)malloc(sizeof(struct stack::StackNide));
	printf("entre the data");
	scanf("%d", &tmp->info);
	if (top == NULL)
	{
		tmp->right = NULL;
		top = tmp;
		tmp->left = NULL;
	}
	else
	{
		tmp->right = top;
		tmp->left = NULL;
		top = tmp;
	}
}

void stack::pop()
{
	struct stack::StackNide *tmp;
	tmp = top;
	top = top->right;
	tmp->right->left = NULL;
	free(tmp);
}

void stack::display()
{
	struct stack::StackNide *tmp;
	tmp = top;
	while (tmp != NULL)
	{
		printf("%d ", tmp->info);
		tmp = tmp->right;
	}
}
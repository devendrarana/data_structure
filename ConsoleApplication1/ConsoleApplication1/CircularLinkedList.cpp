#include "stdafx.h"
#include "CircularLinkedList.h"

void circularlinked(){ int value,item,choice;
struct cnode *last = NULL;
while (1)
{
	printf("you have the following options\n");

	printf("1 dispaly\n");


	printf("2 insert at begining\n");
	printf("3 insert at end\n");
	printf("4 insert after\n");
	printf("5 delete \n");
	printf("14 quit\n");
	printf("enter your choce\n");
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:display(last);
		break;
	case 2:printf("entre the value");
		scanf("%d", &value);
		insertAtBeginning(last, value);
		break;
	case 3:printf("enter the value");
		scanf("%d", &value);
			insertAtEnd(last,value);
		break;
	case 4:printf("entre the value of value to be inserted and and after which item\n");
		scanf("%d %d",&value,&item);
		insertAtAfter(last, value, item);
			break;
	case 5:printf("enter the value to be deletted ");
		scanf("%d", &value);
		deleteBeginning(last,value);
	case 6:exit(1);
	default:
		printf("wrong choice");
	}




}

}
struct cnode * insertAtBeginning(struct cnode *last,int value) {
	struct cnode *tmp = (struct cnode*)malloc(sizeof(struct cnode));
	
	tmp->info = value;
	if (last == NULL) {
		last= tmp;
		tmp->link = tmp;
		return last;
	}
	else {
		tmp->link = last ->link;
		last->link = tmp;
		}
	return last;
 }
void display(struct cnode *last) {
	struct cnode *t;
	if (last == NULL)
		printf("list is empty");
	else {
		
		t=last->link;
		do {
			printf("%d ", t->info);
			t = t->link;
		} while (t != last->link);

	}

}
struct cnode* insertAtEnd(struct cnode*last, int value) {
	struct cnode*tmp = (struct cnode*)malloc(sizeof(struct cnode));
	tmp->info = value;
	if (last == NULL) {
		last = tmp;
		tmp->link=tmp;
		return last;
	}
	tmp->link = last->link;
	last->link = tmp;
	last = tmp;
	return last;
}
struct cnode* insertAtAfter(struct cnode *last, int value, int item) {
	struct cnode*tmp = (struct cnode*)malloc(sizeof(struct cnode));
	struct cnode*t = last;
	tmp->info = value;
	while (t-> info != item)
	{
		t = t ->link;
	}
	t->link;
		tmp->link = t->link;
		t->link = tmp;

		return last;
}
struct cnode* deleteBeginning(struct cnode*last, int value) {

	struct cnode *t, *p;
	if (last == NULL) {
		printf("list is empty");
		return last;
	}

	if (last == last->link && last->info == value)
	{
		t = last;
		last = NULL;
		free(t);
		return last;
	}
	if (last->link->info == value) {
		t = last->link;
		last->link = t->link;
		free(t);
		return last;
	}
	p = last->link;
	while (p->link != NULL)
	{
		if (p->link->info == value) {
			t = p->link;
			p->link = t->link;
			free(t);
			return last;
		}
		p = p->link;

	}


}





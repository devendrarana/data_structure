#include"stdafx.h"
#include"Queue.h"
struct qnode {
	int info;
	struct qnode* link;
};
struct qnode *front = NULL;
struct qnode *rear = NULL;
void Queue(){ int choice,d,item;
while (1) {
	printf("1.insertion\n");
	printf("2.deletion\n");
	printf("3.display\n");
	printf("4.exit\n");
	printf("enter your choice\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:printf("enter the element for insertion\n");
		scanf("%d", &item);
		Qinsert(item);
		break;
	case 2:d = Qdelete();
		printf("deleted item is %d\n", d);
		break;
	case 3:display(front);
		break;
	case 4:exit(1);
		break;
	default:
		printf("wrong choice");
	}



}



}
void Qinsert(int item) {
	struct qnode *t = (struct qnode*)malloc(sizeof(struct qnode));
	t->info = item;
	if (front == NULL)
	{
		t->link = NULL;
		front = t;
		rear = t;
	}
	else {
		rear->link = t;
		t->link = NULL;
		rear = t;
	}
}
int Qdelete() {
	struct qnode *t;
	int item;
	if (front == NULL)
		printf("empty queue or underflow");
	else
	{
		item = front->info;
		t = front;
		front = front->link;
		free(t);
		return item;
	}




}
void display(struct qnode* front) {
	struct qnode* t;
	t = front;
	if (front == NULL)
		printf("no element\n");
	while (front != NULL)
	{
		printf(" %d ", front->info);
		front = front->link;

	}
}
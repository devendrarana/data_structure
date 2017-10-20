#include "stdafx.h"
#include "linked.h"

void showdListOptions() {
	struct node *start = NULL;
	int choice, data, item, pos;
	while (1)
	{
		printf("you have the following options\n");
		printf("1 create list\n");
		printf("2 dispaly\n");
		printf("3 count\n");
		printf("4 search\n");
		printf("5 add to empty\n");
		printf("6 add at end\n");
		printf("7 add after node\n");
		printf("8 add bfore node\n");
		printf("9 add at position\n");
		printf("10 delete\n");
		printf("11 reverse\n");
		printf("12 getMax\n");
		printf("13 getMin\n");
		printf("14 quit\n");
		printf("enter your choce\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			start = createlist(start);
			break;
		case 2:
			display(start);
			break;
		case 3:
			count(start);
			break;
		case 4:
			printf("enter the element to be search");
			scanf("%d", &data);
			search(start, data);
			break;
		case 5:
			printf("enter the element to be search");
			scanf("%d", &data);
			start = addatbeg(start, data);
			break;
		case 6:
			printf("enter the element to be inserted");
			scanf("%d", &data);
			start = addatend(start, data);
			break;

		case 7:
			printf("enter the element to be inserted");
			scanf("%d", &data);
			printf("enter the elmeent afer, to which insert");
			scanf("%d", &item);
			start = addafter(start, data, item);
			break;
		case 8:
			printf("enter the element to be inserted");
			scanf("%d", &data);
			printf("enter the elmeent before, to which insert");
			scanf("%d", &item);
			start = addbefore(start, data, item);
			break;
		case 9:
			printf("enter the element to be inserted");
			scanf("%d", &data);
			printf("enter the elmeent afer, to which insert");
			scanf("%d", &pos);
			start = addatpos(start, data, pos);
			break;
		case 10:
			printf("enter the element to be inserted");
			scanf("%d", &data);

			start = del(start, data);
			break;
		case 11:
			start = reverse(start);
			break;
		case 12: {
			int max = getMax(start);
			if (max != -1) {
				printf(" the max is %d \n", max);
			}
			break;
		}
		case 13: {
			int min = getMin(start);
			if (min != -1) {
				printf(" the min is %d \n", min);
			}
			break;
		}
		case 14:
			exit(1);
		default:
			printf("wrong choice");
		}
	}
}

int getMax(struct node *head) {

	if (head == NULL) {
		printf("Please pass a valid list head \n");
		return -1;
	}

	int max = head->info;
	head = head->link;

	while (head != NULL) {
		if (head->info > max) {
			max = head->info;
		}
		head = head->link;
	}

	return max;
}
int getMin(struct node *head) {

	if (head == NULL) {
		printf("Please pass a valid list head \n");
		return -1;
	}

	int min = head->info;
	head = head->link;

	while (head != NULL) {
		if (head->info < min) {
			min = head->info;
		}
		head = head->link;
	}

	return min;

}



void display(struct node *start)
{
	struct node *p;
	if (start == NULL)
	{
		printf("list is empty");
		return;
	}
	p = start;
	printf("list is ");
	while (p != NULL)
	{
		printf("%d", p->info);
		p = p->link;
	}
	printf("\n");
}



void count(struct node *start)
{
	struct node *p;
	int cnt = 0;
	p = start;
	while (p != NULL)
	{
		p = p->link;
		cnt++;
	}
	printf("%d", cnt);
}




void search(struct node *start, int data)
{
	struct node *p = start;
	int pos = 1;
	while (p != NULL)
	{
		if (p->info == data)
		{
			printf("the data item is %d at posuitoin %d", data, pos);
			return;
		}
		p = p->link;
		pos++;

	}
	printf("item is not found");

}


struct node *addatbeg(struct node *start, int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = start;
	start = tmp;
	return start;
}


struct node *addatend(struct node *start, int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	struct node *p;
	p = start;
	while (p->link != NULL)
	{
		p = p->link;

	}
	tmp->info = data;
	p->link = tmp;
	tmp->link = NULL;
	return start;
}
struct node *addafter(struct node *start, int data, int item)
{
	struct node *tmp, *p;
	tmp = (struct node *)malloc(sizeof(struct node *));
	p = start;
	while (p != NULL)
	{
		if (p->info == item)
		{
			tmp->link = p->link;
			tmp->info = data;
			p->link = tmp;
			return start;

		}
		p = p->link;

	}

	printf("item not present");
	return start;



}
struct node *addbefore(struct node *start, int data, int item)
{

	struct node *tmp, *p;
	tmp = (struct node *)malloc(sizeof(struct node));
	p = start;
	while (p != NULL)
	{
		if (p->link->info == item)
		{
			tmp->info = data;
			tmp->link = p->link;
			p->link = tmp;
			return start;

		}
		p = p->link;

	}
	return start;

}

struct node *addatpos(struct node *start, int data, int pos)
{
	struct node *p, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	p = start;
	int i;
	for (i = 1; i < pos - 1 && p != NULL; i++)
	{

		p = p->link;
	}
	tmp->info = data;
	tmp->link = p->link;
	p->link = tmp;


	return start;
}
struct node *createlist(struct node *start)
{
	int i, n, data;
	printf("enter the number of nodes to be inserted");
	scanf_s("%d", &n);
	start = NULL;
	if (n == 0)
		return start;
	printf("enter the data to be inserted ");
	scanf_s("%d", &data);
	start = addatbeg(start, data);
	for (i = 2; i <= n; i++)
	{
		printf("enter the data to be inserted ");
		scanf_s("%d", &data);
		start = addatend(start, data);

	}
	return start;


}
struct node *del(struct node *start, int data)
{
	struct node *tmp, *p;
	if (start = NULL)
	{
		printf("it is empty ");


	}
	if (start->info == data)
	{
		tmp = start;
		start = start->link;
		free(tmp);
		return start;
	}
	p = start;
	while (p != NULL)
	{
		if (p->link->info == data)
		{
			tmp = p->link;
			p->link = tmp->link;
			free(tmp);

			return start;
		}
		p = p->link;


	}
	return start;
}
struct node *reverse(struct node *start)
{
	struct node *prev, *ptr, *next;
	prev = NULL;
	ptr = start;
	while (ptr != NULL)
	{
		next = ptr->link;
		ptr->link = NULL;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}



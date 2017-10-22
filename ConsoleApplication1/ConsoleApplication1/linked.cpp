#include "stdafx.h"
#include "linked.h"

void link::showdListOptions() {
	struct link::node *start = NULL;
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
			start = link::createlist(start);
			break;
		case 2:
			link::display(start);
			break;
		case 3:
			link::count(start);
			break;
		case 4:
			printf("enter the element to be search");
			scanf("%d", &data);
			link::search(start, data);
			break;
		case 5:
			printf("enter the element to be search");
			scanf("%d", &data);
			start = link::addatbeg(start, data);
			break;
		case 6:
			printf("enter the element to be inserted");
			scanf("%d", &data);
			start = link::addatend(start, data);
			break;

		case 7:
			printf("enter the element to be inserted");
			scanf("%d", &data);
			printf("enter the elmeent afer, to which insert");
			scanf("%d", &item);
			start = link::addafter(start, data, item);
			break;
		case 8:
			printf("enter the element to be inserted");
			scanf("%d", &data);
			printf("enter the elmeent before, to which insert");
			scanf("%d", &item);
			start = link::addbefore(start, data, item);
			break;
		case 9:
			printf("enter the element to be inserted");
			scanf("%d", &data);
			printf("enter the elmeent afer, to which insert");
			scanf("%d", &pos);
			start = link::addatpos(start, data, pos);
			break;
		case 10:
			printf("enter the element to be inserted");
			scanf("%d", &data);

			start = link::del(start, data);
			break;
		case 11:
			start = link::reverse(start);
			break;
		case 12: {
			int max = link::getMax(start);
			if (max != -1) {
				printf(" the max is %d \n", max);
			}
			break;
		}
		case 13: {
			int min = link::getMin(start);
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

int link::getMax(struct link::node *head) {

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
int link::getMin(struct link::node *head) {

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



void link::display(struct link::node *start)
{
	struct link::node *p;
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



void link::count(struct link::node *start)
{
	struct link::node *p;
	int cnt = 0;
	p = start;
	while (p != NULL)
	{
		p = p->link;
		cnt++;
	}
	printf("%d", cnt);
}




void link::search(struct link::node *start, int data)
{
	struct link::node *p = start;
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


struct link::node* link::addatbeg(struct link::node *start, int data)
{
	struct link::node *tmp;
	tmp = (struct link::node *)malloc(sizeof(struct link::node));
	tmp->info = data;
	tmp->link = start;
	start = tmp;
	return start;
}


struct link::node* link::addatend(struct link::node *start, int data)
{
	struct link::node *tmp;
	tmp = (struct link::node *)malloc(sizeof(struct link::node));
	struct link::node *p;
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
struct link::node* link::addafter(struct link::node *start, int data, int item)
{
	struct link::node *tmp, *p;
	tmp = (struct link::node *)malloc(sizeof(struct link::node *));
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
struct link::node* link::addbefore(struct link::node *start, int data, int item)
{

	struct link::node *tmp, *p;
	tmp = (struct link::node *)malloc(sizeof(struct link::node));
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

struct link::node* link::addatpos(struct link::node *start, int data, int pos)
{
	struct link::node *p, *tmp;
	tmp = (struct link::node *)malloc(sizeof(struct link::node));
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
struct link::node* link::createlist(struct link::node *start)
{
	int i, n, data;
	printf("enter the number of nodes to be inserted");
	scanf_s("%d", &n);
	start = NULL;
	if (n == 0)
		return start;
	printf("enter the data to be inserted ");
	scanf_s("%d", &data);
	start = link::addatbeg(start, data);
	for (i = 2; i <= n; i++)
	{
		printf("enter the data to be inserted ");
		scanf_s("%d", &data);
		start = link::addatend(start, data);

	}
	return start;


}
struct link::node* link::del(struct link::node *start, int data)
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
struct link::node* link::reverse(struct link::node *start)
{
	struct link::node *prev, *ptr, *next;
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



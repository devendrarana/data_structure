#pragma once
#include"stdafx.h"
#include"radixsort.h"

struct rnode {
	int info;
	struct rnode* link;

};
struct rnode *start = NULL;
void radixsort() {
	int i, item, value;
	struct rnode *q, *temp;
	temp = (struct rnode*)malloc(sizeof(struct rnode));
	printf("enter the number of elements to be inserted ");
	scanf("%d", &item);
	for (i = 0; i < item; i++) {
		printf("entre the value");
		scanf("%d", &value);
		temp->info = value;
		temp->link = NULL;
		if (start == NULL)
			start = temp;
		else {
			q = start;
			while (q->link != NULL)
			q = q->link;
			
			q->link = temp;
		}
	}
	void radix_sort();
	q = start;
	while (q ->link!= NULL) {
		printf("%d\n", q->info);
		q = q->link;
	}



}
void radix_sort() {
	int i, k, least_sig, most_sig, dig;
	struct rnode *p, *rear[10], *front[10];
	least_sig = 1;
	most_sig = largedig(start);
	for (k = least_sig; k <= most_sig; k++)
	{
		for (i = 0; i < 10; i++) {
			rear[i] = NULL;
			front[i] = NULL;
		}
		for (p = start; p != NULL; p = p->link) {
			dig = digit(p->info, k);
			if (front[dig] == NULL)
				front[dig] = p;
			else
				rear[dig]->link = p;
			rear[dig] = p;

		}
		i = 0;
		while (front[i] == NULL)
			i++;
		start = front[i];
		while (i < 9)
		{
			if (rear[i + 1] != NULL)
				rear[i]->link = front[i + 1];
			else
				rear[i + 1] = rear[i];
			i++;
		}
		rear[9]->link = NULL;

	}
}
int largedig(struct rnode* start) {
	int large = 0;
	struct rnode* q = start;
	while (q != NULL)
	{
		if (q->info > large)
		{
			large = q->info;
		}
		q = q->link;
	}
	int count = 0;
	while (large != 0)
	{

		large = large / 10;
		count++;
	}
	return count;
}
int digit(int number, int k) {
	int i;
	for (i = 1; i <k; i++) {

		number = number / 10;
	}
	return number % 10;

}
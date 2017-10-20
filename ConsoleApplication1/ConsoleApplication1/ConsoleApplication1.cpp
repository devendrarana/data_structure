// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linked.h"

int main(void)
{
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



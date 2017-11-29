#include"stdafx.h"
#include"CircularQueue.h"
#define a 8
int arri[a];
int cfront = -1;
int crear = -1;
void Cqueue() {
	int choice, d, item;
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
			Cinsert(item);
			break;
		case 2:d = Cdelete();
			printf("deleted item is %d\n", d);
			break;
		case 3:Cdisplay(arri);
			break;
		case 4:exit(1);
			break;
		default:
			printf("wrong choice");
		}

	}

	}
	void Cinsert(int item) {
		if (crear == a - 1&&cfront==0)
			printf("overflow\n");
		else {
			if (cfront == -1)
			{
				crear = crear + 1;
				cfront = cfront + 1;
				arri[cfront] = item;

			}
			else
			{
				crear = (crear + 1)%a;
				arri[crear] = item;
			}

		}

	}
	int Cdelete() {
		int item;
		if (cfront > crear||cfront ==-1)
			printf("not possible\n");
		else {
			item = arri[cfront];
			arri[cfront] = NULL;
			cfront = (cfront + 1) % a;
			return item;
		}

	}
	void Cdisplay(int arr[]) {
		int i;
		for (i = 0; i < a; i++)
			printf(" %d \n", arri[i]);
	}
#include "stdafx.h"
#include "heapinsert.h"
void heapinsert() {
	int arr[100];
	int hsize = 0;
	int i,choice, num,value;
	while (1) {
		printf("1 for insert\n");
		printf("2 for delete root\n");
		printf("3 for display\n");
		printf("4 build heap\n");
		printf("5 for exit");
		printf("entre your choice\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:printf("enter the value to be inserted");
			scanf("%d", &value);
			insert(value, arr, &hsize);
			break;
		case 2:
			num=del_root(arr, &hsize);
			printf("the maximum element is %d\n", num);
			break;
		case 3:display(arr, hsize);
			break;
		case 4:printf("enter the size of array");
			scanf("%d", &hsize);
			
			for (i = 1; i <= hsize; i++) {
				scanf("%d", &arr[i]);
			}
			buildheap(arr, hsize);
			break;
		case 5:exit(1);
		default:
			printf("wrong choice");
		}



	}
}
void insert(int num, int arr[], int *p_hsize) {
	(*p_hsize)++;
	arr[*p_hsize] = num;
	restoreup(arr, *p_hsize);

}
void restoreup(int arr[], int i) {
	int k = arr[i];
	int par = i / 2;
	while (arr[par] < arr[i] && par >= 1)
	{
		arr[i] = arr[par];

		i = par;
		par = i / 2;

	}
	arr[i] = k;

}
void restoredown(int arr[], int i, int hsize) {
	int lchild = 2 * i;
	int rchild = lchild + 1;
	int num = arr[i];
	while (rchild <= hsize) {

		if (arr[lchild] < num && arr[rchild] < num)
		{
			return;

		}
		else if (arr[lchild] > arr[rchild])
		{
			arr[i] = arr[lchild];
			i = lchild;
		}

		else
		{
			arr[i] = arr[rchild];
			i = rchild;
		}
		lchild = 2 * i;
		rchild = lchild + 1;
	}
	if (lchild == hsize&&num < arr[lchild])
	{
		arr[i] = arr[lchild];
		arr[lchild] = num;
	}
	arr[i] = num;
}
int del_root(int arr[], int *p_hsize) {
	int max = arr[1];
	arr[1] = arr[*p_hsize];
	(*p_hsize)--;
	restoredown(arr, 1, *p_hsize);
	return max;
}
void display(int arr[], int hsize)
{
	if (hsize == 0)
	{
		printf("heap is empty");
		return;
	}
	int i;
	for (i = 1; i <= hsize; i++)
	{
		printf("%d\n", arr[i]);


	}


}
void buildheap(int arr[], int size) {
	int i;
	for (i = size/2; i >= 1; i--)
		restoredown(arr, i, size);


}
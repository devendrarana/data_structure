#include "quickSortAlgo.h"
#include "stdafx.h"
void quicksort(int arr[6], int num);
void quickSortAlgo() {
	int  num,arr[6], i;
	printf("enter the number to be inserted in array");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		printf("entre the values");
		scanf("%d", &arr[i]);
	}
	quicksort(arr, 6);
	
	for (i = 0; i < num; i++) {
		printf("%d", arr[i]);
	}
	getch();

}
void quick(int arr[], int num, int beg, int end, int *locptr) {
	int left = beg;
	int right = end;
	int temp;
	*locptr = beg;
	step2:
	while (arr[*locptr] <= arr[right] && *locptr != right)
	{
		right--;

	}
	if (*locptr == right)
		return;
	if (arr[*locptr] > arr[right])
	{
		temp = arr[right];
		arr[right] = arr[*locptr];
		arr[*locptr] = temp;
		*locptr = right;
	}
	goto step3;
	step3:
	while (arr[left] < arr[*locptr] && *locptr != left) {
		left++;
	}
	if (*locptr == left)
		return;
	if (arr[left] < arr[*locptr])
	{
		temp = arr[left];
		arr[left] = arr[*locptr];
		arr[*locptr] = temp;
		*locptr=left;
	}

	goto step2;

}
void quicksort(int arr[6], int num) {
	int beg, end, loc, top = -1;
	int lower[10];
	int upper[10];
	if (num > 1) {
		top++;
		lower[top] = 0;
		upper[top] = num - 1;
	}
	while (top != -1) {
		beg = lower[top];
		end = upper[top];
		top--;
		quick(arr, num, beg, end, &loc);
		if (beg < loc - 1) {
			top++;
			lower[top] = beg;
			upper[top] = loc - 1;

		}
		if (loc + 1 < end) {
			top++;
			lower[top] = loc + 1;
			upper[top] = loc - 1;
		}

	}



}
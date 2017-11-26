#include "selectionSortAlgo.h"
#include "stdafx.h"
void selectionSortAlgo() {
	int arr[8], num, i, j, k, temp;
	printf("entre the number of elements");
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		printf("enter the number of elements");
		scanf("%d", &arr[i]);
	}

	for (j = 0; j <= num - 1; j++) {
		int min = arr[j];
		for (k = j + 1; k < num; k++) {
			if (min > arr[k])
			{
				temp = min;
				min = arr[k];
				arr[k] = temp;

			}
			arr[j] = min;

		}

	}

	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);

	}
	getch();

}
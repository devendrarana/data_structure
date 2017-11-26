#include "stdafx.h"
#include "mergeSort.h"
void mergeSort() {
	int arr[6];
	int num, i, j, temp;
	num = 6;
	for (i = 0; i < 6; i++)
	{
		printf("entre the number");
		scanf("%d", &arr[i]);
	}
	getch();
	for (j = 0; j < 6; j++) {
		if (j % 2 == 0 && arr[j] > arr[j + 1]) {
			temp = arr[j + 1];
			arr[j + 1] = arr[j];
			arr[j] = temp;

		}
	}
	mergeSortRecur(arr, 6);
	

	
	

}
void mergeSortRecur(int arr[6],int num) {
	int n, i,j, k;
	j = 0;
	n = 1;
		 do{
		
		int e = 2*n;
		for (j = 0; j < e; j++ )
			for (k = e; k < 2*e; k++ ) {
				if (arr[j] > arr[k]) {
					int temp;
					temp = arr[j];
					arr[j] = arr[k];
					arr[k] = temp;

				}
			}
		n++;
		 } while (k < num);
	
	for (i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);

	}
	getch();
}




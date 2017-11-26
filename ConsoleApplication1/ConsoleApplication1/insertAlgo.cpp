#include "inserAlgo.h"
#include "stdafx.h"
void insertAlgo() {
	int arr[6], temp, num, i, j, k, l, m, temp1;
	printf("entre the number of element");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		printf("entre the element");
		scanf("%d",&arr[i]);
	}
	getch();
	/*for (j = 1; j < num; j++)
	{
		temp = arr[j];

		for (k = j - 1; k >= 0; k--) {
			if (temp < arr[k] && k >= 0)
			{
				arr[k + 1] = arr[k];
			}
			else {
				break;

			}
		}
		arr[k + 1] = temp;
		

	}*/
	
	for (i = 1; i < num; i++)
	{
		 k = i;
		for (j = k - 1; j >= 0; j--&&arr[j] > arr[k])
		{
			temp = arr[k];
			arr[k] = arr[j];
			arr[j] = temp;
			k--;
		}

	}
	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	getch();
	printf("By bubble sort Algorithm");
	for (l = 0; l < num; l++) {
		for (m = 0; m <=num-l-1 ;m++) {
			if (arr[m] > arr[m + 1])
			{
				temp1 = arr[m];
				arr[m ] = arr[m+1];
				arr[m + 1] = temp1;

			}

		}

	}
	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	getch();
	printf("By  modified bubble sort Algorithm");
	getch();
	for (l = 0; l < num; l++) {
		int check = 0;
		int round = 0;
		for (m = 0; m <= num - l - 1; m++) {
			
			if (arr[m] > arr[m + 1])
			{
				int check = 1;
				temp1 = arr[m];
				arr[m] = arr[m + 1];
				arr[m + 1] = temp1;
				round = round + 1;
			}
			
		}
	printf("number of rounds %d", round);
	if(check==0)
		return;
	}
	
	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	getch();


}
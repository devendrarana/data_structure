#include "file4.h"
#include"stdafx.h"
void file4() {
	FILE *fp;
	fp = fopen("myfile4.txt", "w");
	int a, b;
	printf("enter a and b");
	scanf("%d%d", &a, &b);
	fprintf(fp, "sum of %d and %d is %d", a, b, a + b);
	fclose(fp);


}
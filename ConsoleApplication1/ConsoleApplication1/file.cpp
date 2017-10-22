#include"stdafx.h"

void file() {
	char ch;
	FILE *fp;
	fp = fopen("rana.resx", "r");
	if (fp == NULL) {
		printf("it is emPty");
		exit(1);
	}
	ch = fgetc(fp);
	while (!feof(fp))
	{
		printf("%c", ch);
		ch = fgetc(fp);
	}

	fclose(fp);

}
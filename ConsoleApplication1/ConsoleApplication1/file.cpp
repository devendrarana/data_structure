#include"stdafx.h"
#include<conio.h>
void file() {
	char ch;
	FILE *fp;
	fp = fopen("C:\\Users\\Devendra Rana\\Desktop\\rana2.txt", "r");
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
	getch();
}
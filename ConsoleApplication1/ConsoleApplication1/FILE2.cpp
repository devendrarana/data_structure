#include"file2.h"
#include "stdafx.h"
#include<cstdio>
void file2() {
	char str[10];
	FILE *fp;
	fp = fopen("C:\\Users\\Devendra Rana\\Desktop\\rana2.txt", "r");
	if (fp == NULL) {
		printf("file not found");
		exit(1);
	}
	while (fgets(str, 9, fp) != NULL)
	{
		printf("%s", str);
	}
	
	
	fp = fopen("C:\\Users\\Devendra Rana\\Desktop\\rana2.txt", "a");
	printf("entre the string you want to enter \n");
	scanf("%s", str);
	
	fputs(str,fp);
	
	fclose(fp);

}
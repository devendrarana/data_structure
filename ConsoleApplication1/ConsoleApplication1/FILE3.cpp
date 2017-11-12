#include "stdafx.h"
#include "file3.h"
struct book{
int	bookid;
char title[20];
float price;

};
void file3() {
	FILE *fp;
	fp=fopen("myfile.dat", "wb");
	struct book b1;
	printf("entre the bookid booktitle bookprice");
	scanf("%d%s%f", &b1.bookid, b1.title, &b1.price);
	fwrite(&b1, sizeof(b1), 1, fp);
	fclose(fp);


}
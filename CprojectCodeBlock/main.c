#include<stdio.h>

int main(void){ char ch;
FILE *fp;
fp=fopen("rana","r");
if(fp==NULL){
	printf("it is empty");
	exit(1);
}
ch = fgetc(fp);
while(!feof(fp))
{
	printf("%c",ch);
	ch=fgetc(fp);
}

fclose(fp);

}

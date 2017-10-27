#include<stdio.h>

int main(void){ char ch;
FILE *fp;
fp=fopen("C:\\Users\\Devendra Rana\\Desktop\\rana.txt","r");
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

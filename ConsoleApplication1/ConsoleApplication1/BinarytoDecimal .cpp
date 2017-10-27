#include "stdafx.h"
#include "conversion.h"

void conversion(){
	int number,value,choice;
	while (1) {
		printf("1 binary to decimal\n");
		printf("2 decimal to binary\n");
		printf("enter your choice");
		scanf("%d", &choice);
			switch(choice)
			{
			case 1: printf("entre the value\n ");
				scanf("%d", &value);
				binary(value);
				break;
			case 2: printf("entre the value\n");
				scanf("%d", &value);
				decimal(value);
				break;
			default:
				printf("wrong choice");
			}

	}

}
void binary(int n)
{
	int total=0,base = 1,rem;
	while (n > 0) {
		rem = n % 10;
		total =total+rem*base;
		n = n / 10;
		base = base * 2;

	}
	printf("the value is %d",total);

}
void decimal(int n) {
	int rem = n % 2;
	if (n == 0) {
		return ;
	}

	decimal(n / 2);
	printf("%d", rem);

}
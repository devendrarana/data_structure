// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linked.h"

int main(void)
{
	int choice;
	printf("Your Options \n ");
	printf(" 1. LinkedList Operations \n");
	printf(" 2. Add two numbers \n ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		showdListOptions();
		break;
	case 2:
		break;
	default:
		break;
	}
}



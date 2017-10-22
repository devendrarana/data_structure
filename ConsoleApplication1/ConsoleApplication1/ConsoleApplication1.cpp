// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linked.h"
#include "stack.h"
#include "tree.h"
#include "file.h"

int main(void)
{
	int choice;
	printf("Your Options \n ");
	printf(" 1. LinkedList Operations \n");
	printf(" 2. Stack Operations \n ");
	printf(" 3. tree \n ");
	printf(" 4. extraction of a file \n");
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:
		link::showdListOptions();
		break;
	case 2:
		stack::showStackOptions();
		break;
	case 3:
	tree::showTreeOptions();
		break;
	case 4:file();
	default:
		break;
	}
}



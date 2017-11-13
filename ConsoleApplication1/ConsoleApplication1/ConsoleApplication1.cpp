// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linked.h"
#include "stack.h"
#include "tree.h"
#include "file.h"
#include "CircularLinkedList.h"
#include "conversion.h"
#include "doublelinked.h"
#include "BinaryTree.h"
#include "stackarray.h"
#include "file2.h"
#include "file3.h"
#include "file4.h"
int main(void)
{
	int choice;
	printf("Your Options \n ");
	printf(" 1. LinkedList Operations\n");
	printf(" 2. Stack Operations\n");
	printf(" 3. tree\n");
	printf(" 4. extraction of a file\n");
	printf(" 5. circular linked list\n");
	printf(" 6. conversion decimal and binary\n");
	printf(" 7. doublelinkedlist\n");
	printf(" 8. Binarytree\n");
	printf(" 9. Stack using array\n");
	printf(" 10. file using fgets\n");
	printf(" 11.file using fwrite\n");
	printf(" 12.file using fprintf\n");
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
	
		break;
	case 5:circularlinked();
		break;
	case 6:conversion();
		break;
	case 7:doublelinked();
		break;
	case 8:binarytree();
		break;
	case 9:stackArray();
		break;
	case 10:file2();
		break;
	case 11:file3();
		break;
	case 12:file4();
		break;
	default:
		printf("wrong choice");

		
	}
}



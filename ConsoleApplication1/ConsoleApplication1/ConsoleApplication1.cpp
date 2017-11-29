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
#include "insertAlgo.h"
#include "selectionSortAlgo.h"
#include "quickSortAlgo.h"
#include "mergeSort.h"
#include "heapinsert.h"
#include"radixsort.h"
#include"avlTree.h"
#include"Queue.h"
#include"CircularQueue.h"
#include"Graph1.h"
#include"Graph2.h"
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
	printf(" 13.insertion Algorithm and bubble sort\n");
	printf(" 14.selectionSortAlgorithm\n");
	printf(" 15.sorting by quick sort algorithm\n");
	printf(" 16.sorting by merge sortAlgorithm\n");
	printf(" 17.insertion heap\n");
	printf(" 18.radix sort\n");
	printf(" 19.avltree insertion and display\n");
	printf(" 20.queue\n");
	printf(" 21.circular queue\n");
	printf(" 22.adjacency matrix\n");
	printf(" 23.graph with edges\n");
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
	case 13:insertAlgo();
		break;
	case 14:selectionSortAlgo();
		break;
	case 15:quickSortAlgo();
		break;
	case 16:mergeSort();
		break;
	case 17:heapinsert();
		break;
	case 18:radixsort();
		break;
	case 19:avlTree();
		break;
	case 20:Queue();
		break;
	case 21:Cqueue();
		break;
	case 22:adjacent();
		break;
	case 23:Graph2();
		break;
	default:
		printf("wrong choice");

		
	}
}



// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linked.h"
#include "stack.h"
#include "tree.h"
int main(void) {
	int choice,value;
	while(1){
		printf("1 insert\n 2 display\n 3 exit");
		printf("entre your choice");
		scanf("%d", &choice);
		switch (choice) {
		case 1:printf("entre the value to be inserted");
				scanf("%d", &value);
				break;
		case 2:display(root);
			break;
		case 3:exit(0);
		default:
			printf("wrong choice");
		}


}

}
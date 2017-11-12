#include "stdafx.h"
#include "stackarray.h"
#define MAX 7
int stack_array[MAX];
int top = -1;
void stackArray() {
	int choice, value,item;
	while (1) {
		printf("1 for push\n");
		printf("2 for pop\n");
		printf("3 for display\n");
		printf("4 for exit\n");
		printf("entre your choice\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:printf("entre the value\n");
			scanf("%d", &value);
			push(value);
			break;
		case 2: item=pop();
			printf("pop element is %d", item);
			break;
		case 3: display();
			break;
		case 4: exit(1);
			break;
		default:
			printf("wrong choice");
		}
	}
}
void push(int value) {
	if (top == MAX - 1) {
		printf("overflow");
	}
	top = top + 1;
	stack_array[top] = value;
	
}
int pop() {
	if (top == -1) {
		printf("stack underflow");
}
	
	int item = stack_array[top];
	top = top - 1;
	return item;
}
void display() {
	if (top == -1) {
		printf("overflow wali situation");
		
	}
	
		int i;
		for (i = top; i >= 0; i--)
			printf("%d \n", stack_array[i]);
	

}
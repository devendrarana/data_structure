#pragma once
#include<stdio.h>
#include<stdlib.h>
namespace stack
{
	struct StackNide
	{
		int info;
		struct StackNide *left;
		struct StackNide *right;
	};
	void push();
	void pop();
	void display();
	void showStackOptions();
}

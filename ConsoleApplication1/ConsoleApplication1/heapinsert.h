#pragma once
#include "stdafx.h"
void insert(int num, int arr[], int *p_hsize);
void restoreup(int arr[], int i);
void buildheap(int arr[], int size);
void display(int arr[], int hsize);
int del_root(int arr[], int *p_hsize);
void restoredown(int arr[], int i, int hsize);
void restoreup(int arr[], int i);
void insert(int num, int arr[], int *p_hsize);
void heapinsert();
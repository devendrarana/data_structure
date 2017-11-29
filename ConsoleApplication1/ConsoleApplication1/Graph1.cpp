#include"stdafx.h"
#define max 100
int adj[max][max];
void adjacent() {
	int i, j, n, maxedge, choice, origin, destiny;
	printf("enter the number of vertices\n");
	scanf("%d", &n);
	printf("enter 1 for undirected and entre 2 for directed graph\n");
	scanf("%d", &choice);
	if (choice == 1)
		maxedge = n*(n - 1) / 2;
	else
		maxedge = n*(n - 1);
	for (i = 1; i <= maxedge; i++) {

		printf("entre the origin and destiny \n");
		scanf("%d%d", &origin, &destiny);
		if (choice == 1)
		{
			adj[origin][destiny] = 1;
			adj[destiny][origin] = 1;
		}
		else {
			adj[origin][destiny] = 1;
			adj[destiny][origin] = -1;


		}
		if (origin == 5)
			break;
	}
	
	for (i = 0; i < maxedge; i++) {
		for (j = 0; j < maxedge; j++)
			printf("%d", adj[i][j]);
		printf("\n");
	}
	getch();
}
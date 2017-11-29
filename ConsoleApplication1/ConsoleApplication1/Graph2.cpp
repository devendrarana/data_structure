#include"stdafx.h"
#include"Graph2.h"
void Graph2() {
	int choice, i, f, value;
	while (1)
	{
		printf("1. for insertion of vertex\n");
		printf("2. for insertion of edge\n");
		printf("3. for display\n");
		printf("4. delete a vertex\n");
		printf("5. delete a edge\n");
		printf("6. exit\n");
		printf("enter your choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:printf("enter the number of that node\n");
			scanf("%d", &value);
			insertVertex(value);
			break;
		case 2:printf("entre the first root to destination vertex\n");
			scanf("%d%d", &i, &f);
			insertEdge(i, f);
			break;
		case 3:Gdisplay();
			break;
		case 4:printf("delete the node\n");
			scanf("%d", &value);
			deleteVertex(value);
			break;
		case 5:printf("entre the first root to destination vertex\n");
			scanf("%d%d", &i, &f);
			deleteEdge(i, f);
			break;
		case 6: exit(1);
			break;
		default:
			printf("wrong choice\n");
		}

	}





}
struct vertex {
	int info;
	struct vertex* nextVertex;
	struct edge*firstedge;
};
struct vertex *start = NULL;
struct edge {
	struct edge*nextedge;
	struct vertex*destvertex;
};
void insertVertex(int u) {
	struct vertex *tmp, *ptr;
	tmp = (struct vertex*)malloc(sizeof(struct vertex));
	tmp->info = u;
	tmp->nextVertex = NULL;
	tmp->firstedge = NULL;
	if (start == NULL)
	{
		start = tmp;
		return;
	}
	ptr = start;
	while (ptr != NULL) {
		ptr = ptr->nextVertex;
	}
	ptr = tmp;
}
void insertEdge(int u, int v) {
	struct vertex* V1, *V2;
	struct edge* E1, *E2;
	V1 = findVertex(u);
	V2 = findVertex(v);
	E2 = (struct edge*)malloc(sizeof(struct edge));
	E2->destvertex = V2;
	E2->nextedge = NULL;
	if (V1->firstedge == NULL)
	{
		V1->firstedge = E2;
		return;
	}
	E1 = V1->firstedge;

	while (E1 != NULL) {
		E1 = E1->nextedge;
	}
	E1 = E2;



}
struct vertex *findVertex(int a) {

	struct vertex *tmp, *ptr;
	tmp = start;
	while (tmp != NULL)
	{
		if (tmp->info == a)
		{
			ptr = tmp;
			return ptr;
		}

		else
			tmp = tmp->nextVertex;
	}
	ptr = NULL;
	return ptr;

}
void Gdisplay() {
	struct vertex*ptr;
	struct edge*q;
	ptr = start;
	while (ptr != NULL) {
		printf("%d->", ptr->info);
		q = ptr->firstedge;
		while (q != NULL) {
			printf(" %d ", q->destvertex->info);
			q = q->nextedge;
		}
		printf("\n");
		ptr = ptr->nextVertex;
	}
}
void deleteVertex(int a) {
	struct vertex *ptr, *tmp, *pqr;
	struct edge*E, *p;
	tmp = start;
	while (tmp->info != a) {

		tmp = tmp->nextVertex;

	}
	ptr = tmp;

	pqr = tmp->nextVertex;
	tmp = pqr->nextVertex;

	E = ptr->firstedge;

	do {
		p = E;
		E = E->nextedge;
		free(p);
	} while (p != NULL);
	free(ptr);

}
void deleteEdge(int i, int f) {
	struct vertex *ptr1, *ptr2;
	struct edge*E1, *E2 = NULL;
	ptr1 = findVertex(i);
	ptr2 = findVertex(f);
	E1 = ptr1->firstedge;
	while (E1 != NULL) {
		if (E1->nextedge->destvertex->info == f)
		{
			E2 = E1->nextedge;
			return;
		}
		else
		{
			E1 = E1->nextedge;

		}

	}
	E1 = E1->nextedge->nextedge;
	free(E2);




}
#include "Undirected_Graph(BFS).h"
#include "Queue_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int DesendingFunc(LData d1, LData d2)
{
	if (d1 > d2)
		return 1;
	else
		return 0;
}

void GInit(Graph* g, int vers)
{
	g->gArr = (List*)malloc(sizeof(List) * vers);
	g->numE = 0;
	g->numV = vers;

	for (int i = 0; i < vers; i++)
	{
		LInit(&(g->gArr[i]));
		SetSortRule(&(g->gArr[i]), DesendingFunc);
	}

	g->visitInfo = (int*)malloc(sizeof(int) * g->numV); // dynamic allocation as much as Vertex's size
	memset(g->visitInfo, 0, sizeof(int) * g->numV); // initalize array (string.h)
}

void AddEdge(Graph* g, int fromV, int toV)
{
	LInsert(&(g->gArr[fromV]), toV);
	LInsert(&(g->gArr[toV]),fromV);

	(g->numE)++;
}
void DestroyGraph(Graph* g)
{
	free(g->gArr);
	if (g->visitInfo != NULL)
		free(g->visitInfo);
}
void ShowAllGraph(Graph* g)
{
	LData ndata;
	for (int i = 0; i < g->numV; i++)
	{
		printf("%c와 연결되어있는 노드 : ", i+65);
		if (LFirst(&(g->gArr[i]),&ndata))
		{
			printf("%c ", ndata+65);
			while (LNext(&(g->gArr[i]), &ndata))
				printf("%c ", ndata + 65);
			printf("\n");
		}
	}
}

int VisitVertex(Graph* g, int visitV) // helper function (it judges that vertex has been visited or not )
{
	if (g->visitInfo[visitV] == 0) 
	{
		g->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65); // show Vertex visted
		return TRUE;
	}
	return FALSE;
}

void BFShowGraphVertex(Graph* g, int startV)
{
	Queue q;
	int visitV = startV, nextV;
	QInit(&q);
	VisitVertex(g, visitV);

	while ((LFirst(&(g->gArr[visitV]), &nextV)))
	{
		if (VisitVertex(g, nextV));
		Enqueue(&q, nextV);

		while (LNext(&(g->gArr[visitV]), &nextV))
		{
			if(VisitVertex(g, nextV));
				Enqueue(&q, nextV);
		}
		if (IsQEmpty(&q))
			break;
		else
			visitV = Dequeue(&q);
	}
	memset(g->visitInfo, 0, sizeof(int) * g->numV);
}
#include "Undirected_Graph.h"
#include <stdio.h>

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

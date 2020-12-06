#include "Undirected_Graph(DFS).h"
#include "Stack(Array).h"
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

void DFShowGraphVertex(Graph* g, int startV)
{
	Stack s; // Stack is used to see if vertex could visit another vertex
	int visitV = startV;
	int nextV;
	SInit(&s);
	VisitVertex(g, visitV); // visit starting vertex
	SPush(&s, visitV); // push first vertex 

	while (LFirst(&(g->gArr[visitV]), &nextV)) //visit 'visitV' 's first node
	{
		int visitFlag = FALSE;
		if (VisitVertex(g, nextV) == TRUE) // if success visiting
		{
			SPush(&s, visitV); 
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(g->gArr[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(g, nextV) == TRUE)
				{
					SPush(&s, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}
		
		if (visitFlag == FALSE) // if fail visiting 
		{
			if (IsSEmpty(&s) == TRUE) // and stack is empty
				break; // dfs is done;
			else
				visitV = SPop(&s); // else means there's unvisited vertex 
		}
	}
	memset(g->visitInfo, 0, sizeof(int) * g->numV);
}
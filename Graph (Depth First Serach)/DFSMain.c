#include <stdio.h>
#include "Undirected_Graph(DFS).h"

int main(void)
{
	Graph graph;
	GInit(&graph, 4); // A B C D total 4 vertexs

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);

	ShowAllGraph(&graph);

	printf("Start A : ");
	DFShowGraphVertex(&graph, A); printf("\n");
	
	DestroyGraph(&graph);
	return 0;
}
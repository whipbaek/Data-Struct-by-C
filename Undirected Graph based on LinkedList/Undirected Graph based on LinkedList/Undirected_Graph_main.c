#include <stdio.h>
#include "Undirected_Graph.h"

int main(void)
{
	Graph g;
	GInit(&g,5);
	AddEdge(&g,A,B); AddEdge(&g, B,D);
	AddEdge(&g,C,B); AddEdge(&g, D, E);
	AddEdge(&g, A,E);

	ShowAllGraph(&g);
	DestroyGraph(&g);
	return 0;
}
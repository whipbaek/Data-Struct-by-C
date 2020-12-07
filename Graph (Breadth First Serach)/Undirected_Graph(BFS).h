#pragma once
#include "LinkedList_Sorting.h"

enum { A,B,C,D,E,F,G,H,I,J,K }; //Vertexs

typedef struct _graph {
	int numV; //num of Vertex
	int numE; //num of Edge
	List* gArr;
	int* visitInfo; // Variable for visiting info
}Graph;


void GInit(Graph* g, int vers);
void AddEdge(Graph* g, int fromV, int toV);
void DestroyGraph(Graph* g);
void ShowAllGraph(Graph* g);

void BFShowGraphVertex(Graph* g, int startV); // new function 

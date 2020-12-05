#pragma once
#define TRUE 1
#define FALSE 0

typedef int LData;
typedef int(compfunc)(LData d1, LData d2);
typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct {
	Node* head;
	Node* beofre;
	Node* cur;
	int numofdata;
	compfunc* cf;
}List;

void LInit(List* l);
void SetSortRule(List* l, compfunc* nf); // register compfunc
void LInsert(List* l, LData ndata);
void FInsert(List* l, LData ndata); // if no comp func
void SInsert(List* l, LData ndata); // else if list has sorting func 
int LFirst(List* l, LData* ndata);
int LNext(List* l, LData* ndata);
LData LRmove(List* l);
int LCount(List* l);

void PrintNode(List* l);

#include "LinkedList_Sorting.h"
#include <stdlib.h>
#include <stdio.h>
void LInit(List* l)
{
	l->head = (Node*)malloc(sizeof(Node));
	l->head->next = NULL;
	l->cf = NULL;
	l->numofdata = 0;
}
void SetSortRule(List* l, compfunc* nf)
{
	l->cf = nf;
}
void LInsert(List* l, LData ndata)
{
	if (l->cf != NULL)
		SInsert(l, ndata);
	else
		FInsert(l, ndata);
}
void FInsert(List* l, LData ndata)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = ndata;
	newNode->next = NULL;

	newNode->next = l->head->next;
	l->head->next = newNode;
	(l->numofdata)++;
}
void SInsert(List* l, LData ndata)
{
	Node* pre = l->head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = ndata;
	newNode->next = NULL;

	while (pre->next != NULL && l->cf(ndata,pre->next->data) != 0) // search next data
		pre = pre->next;

	newNode->next = pre->next;
	pre->next = newNode;
	(l->numofdata)++;
}
int LFirst(List* l, LData* ndata)
{
	if (l->numofdata == 0)
		return FALSE;
	l->beofre = l->head;
	l->cur = l->beofre->next;

	*ndata = l->cur->data;
	(l->numofdata)++;
	return TRUE;
}
int LNext(List* l, LData* ndata)
{
	if (l->cur->next == NULL)
		return FALSE;
	l->beofre = l->cur;
	l->cur = l->cur->next;

	*ndata = l->cur->data;
	(l->numofdata)++;
	return TRUE;
}
LData LRmove(List* l)
{
	Node* rpos;
	LData rdata;

	if (l->numofdata == 0)
		return FALSE;

	rpos = l->cur;
	rdata = rpos->data;
	l->beofre->next = l->cur->next;
	l->cur = l->beofre;

	(l->numofdata)--;
	free(rpos);
	return rdata;
}
int LCount(List* l)
{
	return l->numofdata;
}

void PrintNode(List* l)
{
	Node* temp = l->head->next;
	if (temp->data == NULL)
		return;
	printf("%d ", temp->data);
	while (temp->next != NULL)
	{
		temp = temp->next;
		printf("%d ", temp->data);
	}
	
}
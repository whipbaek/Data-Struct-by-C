#include "Queue_array.h"

void QInit(Queue* q)
{
	q->front = 0;
	q->rear = 0;
	q->numofdata = 0;
}
int IsQEmpty(Queue* q)
{
	if (q->numofdata == 0)
		return TRUE;
	else
		return FALSE;
}
int GetNextIdx(QData idx)
{
	if (idx + 1 == ARR_LEN)
		return 0;
	else
		return idx + 1;
}
void Enqueue(Queue* q, QData ndata)
{
	if (GetNextIdx(q->front) == q->rear)
		return;
	q->front = GetNextIdx(q->front);
	q->arr[q->front] = ndata;
	(q->numofdata)++;
}

QData Dequeue(Queue* q)
{
	if (IsQEmpty(q))
		return -1;

	q->rear = GetNextIdx(q->rear);
	(q->numofdata)--;
	return q->arr[q->rear];
}
QData Qpeek(Queue* q)
{
	return q->arr[q->rear];
}
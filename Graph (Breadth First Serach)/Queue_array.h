#pragma once

#define ARR_LEN 100
#define TRUE 1
#define FALSE 0
typedef int QData;
typedef struct _queue {
	int front;
	int rear;
	int numofdata;
	QData arr[ARR_LEN];
}Queue;

void QInit(Queue* q);
int IsQEmpty(Queue* q);
void Enqueue(Queue* q,QData ndata);
QData Dequeue(Queue* q);
QData Qpeek(Queue* q);
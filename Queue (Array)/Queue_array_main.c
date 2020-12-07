#include <stdio.h>
#include "Queue_array.h"

int main(void)
{
	Queue q;
	QInit(&q);
	Enqueue(&q, 10); Enqueue(&q, 20);
	Enqueue(&q, 30); Enqueue(&q, 40); Enqueue(&q, 50);

	while (!IsQEmpty(&q))
		printf("%d ", Dequeue(&q));
	printf("\n");
	return 0;
}
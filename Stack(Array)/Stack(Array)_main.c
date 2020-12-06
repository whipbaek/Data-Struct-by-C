#include <stdio.h>
#include "Stack(Array).h"

int main(void)
{
	Stack s;
	SInit(&s);

	SPush(&s, 10); SPush(&s, 20);
	SPush(&s, 30); SPush(&s, 40);
	SPush(&s, 50);
	
	while (!IsSEmpty(&s))
		printf("%d ", SPop(&s));
	printf("\n");

	return 0;
}
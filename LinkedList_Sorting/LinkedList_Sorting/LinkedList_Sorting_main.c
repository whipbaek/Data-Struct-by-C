#include "LinkedList_Sorting.h"
#include <stdio.h>

int DesendingFunc(LData d1, LData d2)
{
	if (d1 > d2) 
		return 1; 
	else
		return 0;
}
int main(void)
{
	List l;
	LData ndata;
	LInit(&l); SetSortRule(&l, DesendingFunc);
	
	LInsert(&l, 20); LInsert(&l, 10);
	LInsert(&l, 40); LInsert(&l, 5);
	LInsert(&l, 60);

	PrintNode(&l);
	
	if (LFirst(&l, &ndata))
	{
		if (ndata == 40)
			LRmove(&l);
		while (LNext(&l, &ndata))
		{
			if (ndata == 40)
				LRmove(&l);
		}
	}
	printf("\n");
	PrintNode(&l);
	return 0;
}
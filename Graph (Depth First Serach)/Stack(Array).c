#include "Stack(Array).h"
#include <stdio.h>
void SInit(Stack* s)
{
	s->idx = -1;
	s->numodfdata = 0;
}
int IsSEmpty(Stack* s)
{
	if (s->numodfdata == 0)
		return TRUE;
	else
		return FALSE;
}
void SPush(Stack* s, SData ndata)
{
	if (s->numodfdata == ARR_LEN)
	{
		puts("Stack is Full\n");
		return;
	}
	(s->idx)++;
	s->larr[s->idx] = ndata;
	(s->numodfdata)++;
}

SData SPop(Stack* s)
{
	SData rdata;
	if (s->numodfdata == 0)
	{
		printf("No Data in Stack\n");
		return FALSE;
	}
	rdata = s->larr[s->idx];
	(s->idx)--;
	(s->numodfdata)--;
	return rdata;
}

SData SPeek(Stack* s)
{
	return s->larr[s->idx];
}

void ShowStack(Stack* s)
{
	int nidx = 0;
	printf("now Stack : ");
	while (nidx < s->numodfdata)
		printf("%c ", s->larr[nidx++] + 65);
	printf("\n");
}

#pragma once
#define ARR_LEN 100
#define TRUE 1
#define FALSE 0

typedef int SData;
typedef struct {
	int idx;
	int numodfdata;
	SData larr[ARR_LEN];
}Stack;

void SInit(Stack* s);
int IsSEmpty(Stack* s);
void SPush(Stack* s, SData ndata);
SData SPop(Stack* s);
SData SPeek(Stack* s);
void ShowStack(Stack* s);



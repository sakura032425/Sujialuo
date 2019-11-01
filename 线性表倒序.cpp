#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <iostream>
#define LIST_INIT_SIZE          100
#define LISTINCEREMENT          10
typedef int ElemType;
using namespace std;
typedef struct {
	ElemType *	elem;
	int		length;
	int		listsize;
} SqList;
SqList L;
int main()
{
	int InitList(SqList& L);
	void ListInsert(SqList& L, int i, ElemType e);
	void Showlist(SqList L);
	void Inverted(SqList &L);
	InitList(L);
	int a,k=1;
	cout<<"Input :";
	while(cin>>a)
	{
		ListInsert(L, k, a);
		k++;
	}
	Inverted(L);
	cout<<"Output:";
	Showlist(L);
}
int InitList(SqList& L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 1;
}
void ListInsert(SqList& L, int i, ElemType e)
{
	if ((i < 1) || (i > L.length + 1))
		return;
	if (L.length > L.listsize) {
		L.elem = (ElemType *)realloc(L.elem, (L.listsize + 10) * sizeof(ElemType));
		L.listsize += LISTINCEREMENT;
	}
	int k = L.length - 1;
	for (; k >= i - 1; k--)
		*(L.elem + k + 1) = *(L.elem + k);
	*(L.elem + i - 1) = e;
	L.length++;
}
void Showlist(SqList L)
{
	for(int i=0;i<L.length;i++)
	cout<<*(L.elem+i)<<" ";
	cout<<endl;
}
void Inverted(SqList &L)
{
	for(int i=1;i<L.length;i++)
	{
		int k=*(L.elem+i);
		for(int j=i-1;j>=0;j--)
		L.elem[j+1]=L.elem[j];
		L.elem[0]=k;
	}
}

#include <iostream>
#include <stdlib.h>
#define LIST_INIT_SIZE          100
#define LISTINCEREMENT          10
typedef int ElemType;
using namespace std;
typedef struct {
	ElemType *	elem;
	int		length;
	int		listsize;
} SqList;
int main()
{
	SqList L, La, Lb, Lc;
	int InitList(SqList & L);
	void DestroyList(SqList & L);
	void ClearList(SqList & L);
	int ListEmpty(SqList L);
	int Listlength(SqList L);
	int GetElem(SqList L, int i, ElemType & e);
	int compare(int a, int b);
	int LocateElem(SqList L, ElemType e);
	void PriorElem(SqList L, ElemType cur_e, ElemType & pre_e);
	void NextElem(SqList L, ElemType cur_e, ElemType & next_e);
	void ListInsert(SqList & L, int i, ElemType e);
	void ListDelete(SqList & L, int i, ElemType & e);
	void visit(ElemType & e);
	void ListTraverse(SqList L);
	void Intersection(SqList La, SqList Lb, SqList Lc);
	void Union(SqList La, SqList Lb);
	void Difference(SqList & La, SqList Lb);

	return 0;
}


int InitList(SqList& L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 1;
}


void DestroyList(SqList& L)
{
	free(L.elem);
	L.length = 0;
	L.listsize = 0;
	L.elem = NULL;
}


void ClearList(SqList& L)
{
	L.length = 0;
}


int ListEmpty(SqList L)
{
	if (L.elem == NULL)
		return 0;
	else
		return 1;
}


int Listlength(SqList L)
{
	return L.length;
}


int GetElem(SqList L, int i, ElemType& e)
{
	if ((i > L.length) || (i < 1))
		return 0;

	e = *L.elem + i - 1;
	return 1;
}


int compare(int a, int b)
{
	if (a == b)
		return 1;
	else
		return 0;
}


int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
		if (compare(e, *L.elem + i))
			return i + 1;

	return 0;
}


void PriorElem(SqList L, ElemType cur_e, ElemType& pre_e)
{
	int i = 0;

	for ( ; i < L.length; i++)
		if (*L.elem + i == cur_e)
			break;
	if (i <= 1)
		return;

	pre_e = *L.elem + i - 1;
}


void NextElem(SqList L, ElemType cur_e, ElemType& next_e)
{
	int i = 0;

	for ( ; i < L.length; i++)
		if (*L.elem + i == cur_e)
			break;
	if (i == L.length - 1)
		return;

	next_e = *L.elem + i - 1;
}


void ListInsert(SqList& L, int i, ElemType e)
{
	if ((i < 1) || (i > L.length))
		return;

	if (L.length >= L.listsize) {
		L.elem = (ElemType *)realloc(L.elem, (L.listsize + 10) * sizeof(ElemType));
		L.listsize += LISTINCEREMENT;
	}
	int k = L.length - 1;
	for ( ; k >= i - 1; k--)
		*(L.elem + k + 1) = *(L.elem + k);
	*(L.elem + k) = e;
	L.length++;
}


void ListDelete(SqList& L, int i, ElemType& e)
{
	if ((i < 1) || (i > L.length))
		return;

	e = *(L.elem + i - 1);
	for ( ; i <= L.length; i++)
		*(L.elem + i - 1) = *(L.elem + i);
	L.length--;
}


void visit(ElemType& e)
{
	e++;
}

void ListTraverse(SqList L)
{
	for (int i = 0; i < L.length; i++)
		visit(*(L.elem + i));
}


void Intersection(SqList La, SqList Lb, SqList& Lc)
{
	int k = 0;

	for (int i = 0; i < La.length; i++) {
		for (int j = 0; j < Lb.length; j++) {
			if (La.length == Lb.length) {
				*(Lc.elem + k) = *(La.elem + i);
				k++;
				Lc.length++;
			}
		}
	}
}


void Union(SqList& La, SqList Lb)
{
	for (int i = 0; i < La.length; i++) {
		int k = 1;
		for (int j = 0; j < Lb.length; j++) {
			if (*(La.elem + i) == *(Lb.elem + j))
				k = 0;
			break;
		}
		if (k) {
			*Lb.elem = *(La.elem + i);
			Lb.length++;
		}
	}
}


void Difference(SqList& La, SqList Lb)
{
	for (int i = 0; i < La.length;) {
		int k = 0;
		for (int j = 0; j < Lb.length; j++) {
			if (*(La.elem + i) == *(Lb.elem + j))
				k = 1;
			break;
		}
		if (k) {
			ElemType e;

			ListDelete(La, i, e);
			continue;
		}
		i++;
	}
}

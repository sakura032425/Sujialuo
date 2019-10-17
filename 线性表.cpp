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
int main()
{
	srand((unsigned)time(NULL));
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
	void Intersection(SqList La, SqList Lb, SqList & Lc);
	void Union(SqList La, SqList & Lb);
	void Difference(SqList & La, SqList Lb);
	InitList(La);
	InitList(Lb);
	InitList(Lc);
	for (int i = 1; i <= 5; i++)
		ListInsert(La, i, i);
	for (int i = 3; i <= 7; i++)
		ListInsert(Lb, i - 2, i);
	while (1) {
		cout << "***************************************************" << endl;
		cout << "*              线性表操作                         *" << endl;
		cout << "*              1 创建                             *" << endl;
		cout << "*              2 销毁                             *" << endl;
		cout << "*              3 清空                             *" << endl;
		cout << "*              4 判断是否为空                     *" << endl;
		cout << "*              5 判断长度                         *" << endl;
		cout << "*              6 输出位置数值                     *" << endl;
		cout << "*              7 定位                             *" << endl;
		cout << "*              8 获得前驱                         *" << endl;
		cout << "*              9 获取后继                         *" << endl;
		cout << "*              10 插入数据                        *" << endl;
		cout << "*              11 删除数据                        *" << endl;
		cout << "*              12 对每个数据进行操作              *" << endl;
		cout << "*              13 交集                            *" << endl;
		cout << "*              14 并集                            *" << endl;
		cout << "*              15 差集                            *" << endl;
		cout << "请选择一个功能" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1: {
			InitList(L);
			break;
		}
		case 2: {
			DestroyList(L);
			break;
		}
		case 3: {
			ClearList(L);
			break;
		}
		case 4: {
			if (ListEmpty(L))
				cout << "不为空" << endl;
			else
				cout << "L为空表" << endl;
			break;
		}
		case 5: {
			cout << "表的长度为:" << Listlength(L) << endl;
			break;
		}
		case 6: {
			int i, e;
			cout << "请输入数据的位置:";
			cin >> i;
			GetElem(L, i, e);
			cout << e << endl;
			break;
		}
		case 7: {
			int e;
			cout << "请输入要查找的数据:";
			cin >> e;
			cout << LocateElem(L, e) << endl;
			break;
		}
		case 8: {
			int cur_e, pre_e;
			cout << "请输入数据:";
			cin >> cur_e;
			PriorElem(L, cur_e, pre_e);
			cout << pre_e << endl;
			break;
		}
		case 9: {
			int cur_e, next_e;
			cout << "请输入数据:";
			cin >> cur_e;
			NextElem(L, cur_e, next_e);
			cout << next_e << endl;
			break;
		}
		case 10: {
			int i, e;
			cout << "请输入要插入数据的位置:";
			cin >> i;
			cout << "请输入要插入的数据:";
			cin >> e;
			ListInsert(L, i, e);
			break;
		}
		case 11: {
			int i, e;
			cout << "请输入要删除数据的位置:";
			cin >> i;
			ListDelete(L, i, e);
			cout << "被删除的数据为" << e << endl;
			break;
		}
		case 12: {
			ListTraverse(L);
			break;
		}
		case 13: {
			Intersection(La, Lb, Lc);
			for (int i = 0; i < Lc.length; i++)
				cout << *Lc.elem + i << " ";
			cout << endl;
			break;
		}
		case 14: {
			Union(La, Lb);
			for (int i = 0; i < Lb.length; i++)
				cout << *(Lb.elem + i) << " ";
			break;
		}
		case 15: {
			Difference(La, Lb);
			for (int i = 0; i < La.length; i++)
				cout << *(La.elem + i) << " ";
			break;
		}
		default: {
			cout << "退出程序" << endl;
			return 0;
			break;
		}
		}
		system("pause");
		system("cls");
	}
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

	e = *(L.elem + i - 1);
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

	for (; i < L.length; i++)
		if (*(L.elem + i) == cur_e)
			break;
	if (i < 1)
		return;

	pre_e = *(L.elem + i - 1);
}


void NextElem(SqList L, ElemType cur_e, ElemType& next_e)
{
	int i = 0;

	for (; i < L.length; i++)
		if (*(L.elem + i) == cur_e)
			break;
	if (i == L.length - 1)
		return;

	next_e = *(L.elem + i + 1);
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


void ListDelete(SqList& L, int i, ElemType& e)
{
	if ((i < 1) || (i > L.length))
		return;

	e = *(L.elem + i - 1);
	for (; i <= L.length; i++)
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

	ClearList(Lc);
	for (int i = 0; i < La.length; i++) {
		for (int j = 0; j < Lb.length; j++) {
			if (*(La.elem + i) == *(Lb.elem + j)) {
				*(Lc.elem + k) = *(La.elem + i);
				k++;
				Lc.length++;
			}
		}
	}
}


void Union(SqList La, SqList& Lb)
{
	for (int i = 0; i < La.length; i++) {
		int k = 1;
		for (int j = 0; j < Lb.length; j++) {
			if (*(La.elem + i) == *(Lb.elem + j)) {
				k = 0;
				break;
			}
		}
		if (k) {
			*(Lb.elem + Lb.length) = *(La.elem + i);
			Lb.length++;
		}
	}
}

void Difference(SqList& La, SqList Lb)
{
	for (int i = 0; i < La.length;) {
		int k = 0;
		for (int j = 0; j < Lb.length; j++) {
			if (*(La.elem + i) == *(Lb.elem + j)) {
				k = 1;
				break;
			}
		}
		if (k) {
			ElemType e;

			ListDelete(La, i + 1, e);
			continue;
		}
		i++;
	}
}

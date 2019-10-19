#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode {
	ElemType	data;
	LNode *		next;
}LNode, *Linklist;
Linklist L;
int main()
{
	void InitList(Linklist & L);
	void DestryList(Linklist & L);
	void ClearList(Linklist & L);
	int ListLength(Linklist L);
	int GetElem(Linklist L, int n);
	int LocateElem(Linklist L, int e);
	int PriorElem(Linklist L, int e);
	int NextElem(Linklist L, int e);
	void ListInsert(Linklist L, int n, int e);
	int ListDelete(Linklist L, int n);
	void ShowList(Linklist L);
	void InputList(Linklist & L);
	void MergeList1(Linklist La, Linklist Lb, Linklist & Lc);
	void MergeList2(Linklist & La, Linklist & Lb);
	Linklist La, Lb, Lc;

	InitList(La);
	InitList(Lb);
	InitList(Lc);
	Linklist p1 = La;

	for (int i = 1; i < 6; i++) {
		p1->next = (Linklist)malloc(sizeof(LNode));
		p1 = p1->next;
		p1->data = i;
		p1->next = NULL;
	}
	p1 = Lb;
	for (int i = 3; i < 8; i++) {
		p1->next = (Linklist)malloc(sizeof(LNode));
		p1 = p1->next;
		p1->data = i;
		p1->next = NULL;
	}

	while (1) {
		cout << "***************************************************" << endl;
		cout << "*              链表操作                           *" << endl;
		cout << "*              1 初始化链表                       *" << endl;
		cout << "*              2 销毁链表                         *" << endl;
		cout << "*              3 链表中元素个数                   *" << endl;
		cout << "*              4 所指位序元素值                   *" << endl;
		cout << "*              5 链表中已存在元素位序             *" << endl;
		cout << "*              6 求直接前驱                       *" << endl;
		cout << "*              7 求直接后继                       *" << endl;
		cout << "*              8 在第i个位置插入元素              *" << endl;
		cout << "*              9 删除第i个元素                    *" << endl;
		cout << "*              10 输出所有链表元素                *" << endl;
		cout << "*              11 输入链表元素                    *" << endl;
		cout << "*              12 归并1                           *" << endl;
		cout << "*              13 归并2(未开辟新空间)             *" << endl;
		cout << "**************************************************" << endl;
		cout << "请选择一个功能" << endl;
		cout << endl;
		int x;
		cin >> x;
		switch (x) {
		case 1: {
			InitList(L);
			cout << "初始化成功" << endl;
			break;
		}
		case 2: {
			DestryList(L);
			cout << "销毁成功" << endl;
			break;
		}
		case 3: {
			cout << "元素个数为" << ListLength(L) << endl;
			break;
		}
		case 4: {
			cout << "请输入位序值：";
			int i;
			cin >> i;
			cout << "该位序元素为：" << GetElem(L, i) << endl;
			break;
		}
		case 5: {
			int e;
			cout << "请输入元素值:";
			cin >> e;
			cout << LocateElem(L, e) << endl;
			break;
		}
		case 6: {
			int e;
			cout << "请输入元素值:";
			cin >> e;
			cout << PriorElem(L, e) << endl;
			break;
		}
		case 7: {
			int e;
			cout << "请输入元素值:";
			cin >> e;
			cout << NextElem(L, e) << endl;
			break;
		}
		case 8: {
			int i, e;
			cout << "请输入位序";
			cin >> i;
			cout << "请输入元素";
			cin >> e;
			ListInsert(L, i, e);
			break;
		}
		case 9: {
			int i;
			cout << "请输入位序";
			cin >> i;
			ListDelete(L, i);
			break;
		}
		case 10: {
			ShowList(L);
			cout << endl;
			break;
		}
		case 11: {
			InputList(L);
			break;
		}
		case 12: {
			ShowList(La);
			cout << endl;
			ShowList(Lb);
			cout << endl;
			MergeList1(La, Lb, Lc);
			ShowList(Lc);
			cout << endl;
			break;
		}
		case 13: {
			ShowList(La);
			cout << endl;
			ShowList(Lb);
			cout << endl;
			MergeList2(La, Lb);
			ShowList(La);
			cout << endl;
		}
		default: {
			return 0;
		}
		}
		system("pause");
		system("cls");
	}
}


void InitList(Linklist &L)
{
	L = (Linklist)malloc(sizeof(LNode));
	if (!L)
		exit(1);
	L->data = 0;
}
void DestryList(Linklist &L)
{
	Linklist p1, p2;

	p1 = p2 = L;
	while (p1 != NULL) {
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	L = NULL;
}
void ClearList(Linklist &L)
{
	Linklist p1, p2;

	p1 = p2 = L->next;
	while (p1 != NULL) {
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	L->next = NULL;
}
int ListLength(Linklist L)
{
	int i = 0;
	Linklist p = L->next;

	while (p) {
		p = p->next;
		i++;
	}
	return i;
}
int GetElem(Linklist L, int n)
{
	int i = 0;
	Linklist p = L;

	while (n - i) {
		p = p->next;
		i++;
	}
	return p->data;
}
int LocateElem(Linklist L, int e)
{
	int i = 0;
	Linklist p = L;

	while ((p->data) - e) {
		p = p->next;
		i++;
	}
	if (p == NULL) {
		cout << "未找到该数据" << endl;
		return 0;
	}
	return i;
}
int PriorElem(Linklist L, int e)
{
	Linklist p = L, p1 = L;

	while (p) {
		p = p->next;
		if (p->data == e && p1 != L->next)
			return p1->data;
		p1 = p;
	}
	cout << "未找到直接前驱" << endl;
	return 0;
}
int NextElem(Linklist L, int e)
{
	Linklist p = L->next;

	while (p) {
		if (p->data == e && p->next != NULL)
			return p->next->data;
		p = p->next;
	}
	cout << "未找到直接后继" << endl;
	return 0;
}
void ListInsert(Linklist L, int n, int e)
{
	int i = 0;
	Linklist p = L, p1;

	while (p && n - i - 1) {
		p = p->next;
		i++;
	}
	p1 = p->next;
	p->next = (Linklist)malloc(sizeof(LNode));
	p->next->data = e;
	p->next->next = p1;
}
int ListDelete(Linklist L, int n)
{
	int i = 0;
	Linklist p = L, p1;

	while (p && n - i - 1) {
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	p1 = p->next->next;
	int e = p->next->data;
	free(p->next);
	p->next = p1;
	return e;
}
void ShowList(Linklist L)
{
	Linklist p = L->next;

	while (p) {
		cout << p->data << "\t";
		p = p->next;
	}
}
void InputList(Linklist &L)
{
	int e;
	Linklist p = L;

	while (cin >> e) {
		if (e == 0)
			return;
		p->next = (Linklist)malloc(sizeof(LNode));
		p = p->next;
		p->data = e;
		p->next = NULL;
	}
}
void MergeList1(Linklist La, Linklist Lb, Linklist &Lc)
{
	Linklist p = Lc;
	Linklist pa = La->next, pb = Lb->next;

	while (pa && pb) {
		if (pa->data >= pb->data) {
			p->next = (Linklist)malloc(sizeof(LNode));
			p = p->next;
			p->data = pb->data;
			p->next = NULL;
			pb = pb->next;
		} else {
			p->next = (Linklist)malloc(sizeof(LNode));
			p = p->next;
			p->data = pa->data;
			p->next = NULL;
			pa = pa->next;
		}
	}
	if (pa)
		p->next = pa;
	else
		p->next = pb;
}
void MergeList2(Linklist &La, Linklist &Lb)
{
	Linklist p1 = (La->next->data < Lb->next->data ? La->next : Lb->next);
	Linklist p2 = (La->next->data >= Lb->next->data ? La->next : Lb->next);

	while (p1->next && p2) {
		if (p2->data <= p1->next->data) {
			Linklist p3 = p1->next;
			p1->next = p2;
			p2 = p2->next;
			p1 = p1->next;
			p1->next = p3;
		} else {
			p1 = p1->next;
		}
	}
	if (p2)
		p1->next = p2;
}

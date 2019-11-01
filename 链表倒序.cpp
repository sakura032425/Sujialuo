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
	void InitList(Linklist &L);
	void InputList(Linklist &L);
	void ShowList(Linklist L);
	void Inverted(Linklist L);
	InitList(L);
	cout<<"Input(0):";
	InputList(L);
	Inverted(L);
	cout<<"Output  :";
	ShowList(L);
	return 0;
}
void InitList(Linklist &L)
{
	L = (Linklist)malloc(sizeof(LNode));
	if (!L)
		exit(1);
	L->data = 0;
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
void ShowList(Linklist L)
{
	Linklist p = L->next;

	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
}
void Inverted(Linklist L)
{
	Linklist p,p1,p2,q;
	p1=p2=L->next->next;
	q=L->next;
	while(p1)
	{
		p=L->next;
		p2=p2->next;
		L->next=p1;
		p1->next=p;
		q->next=p2;
		p1=p2;
	}
}

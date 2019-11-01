#include <iostream>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
using namespace std;

typedef int SElemType;
typedef struct {
	SElemType *	base;
	SElemType *	top;
	int		stacksize;
}SqStack;


void InitStack(SqStack &S);
void DestroyStack(SqStack &S);
void ClearStack(SqStack &S);
int StackEmpty(SqStack S);
int StackLength(SqStack S);
int GetTop(SqStack S, int &e);
void Push(SqStack &S, int e);
int Pop(SqStack &S, int &e);
int StackTraverse(SqStack S);
void conversion();

int main()
{
	int q, i;
	SqStack S;

	while (1) {
		cout << "**********           栈               ***************" << endl;
		cout << "**********      1  初始化栈           ***************" << endl;
		cout << "**********      2  销毁栈             ***************" << endl;
		cout << "**********      3  清空栈             ***************" << endl;
		cout << "**********      4  检查是否为空       ***************" << endl;
		cout << "**********      5  栈的长度           ***************" << endl;
		cout << "**********      6  得到栈顶元素的值   ***************" << endl;
		cout << "**********      7  入栈               ***************" << endl;
		cout << "**********      8  出栈               ***************" << endl;
		cout << "**********      9  弹出栈中所有元素   ***************" << endl;
		cout << "**********      10 十进制转换八进制   ***************" << endl;
		cout << "**********      11 退出               ***************" << endl;
		cin >> i;
		if (i < 1 || i > 11) {
			cout << "不合法输入，请重试" << endl;
			system("pause");
			system("cls");
			continue;
		}
		switch (i) {
		case 1:
			InitStack(S);
			cout << "建栈成功" << endl;
			system("pause");
			break;
		case 2:
			DestroyStack(S);
			cout << "销毁栈成功" << endl;
			system("pause");
			break;
		case 3:
			ClearStack(S);
			cout << "清除栈成功" << endl;
			system("pause");
			break;
		case 4:
			if (!StackEmpty(S))
				cout << "栈为空" << endl;
			else
				cout << "栈不为空" << endl;
			system("pause");
			break;
		case 5:
			if (!StackLength(S))
				cout << "栈为空" << endl;
			else
				cout << "栈的长度为：" << StackLength(S) << endl;
			system("pause");
			break;
		case 6:
			if (!GetTop(S, q))
				cout << "栈为空" << endl;
			else
				cout << "栈顶元素的值为：" << q << endl;
			system("pause");
			break;
		case 7:
			cout << "请输入要入栈元素的值：" << endl;
			cin >> q;
			Push(S, q);
			cout << "入栈成功" << endl;
			system("pause");
			break;
		case 8:
			if (!Pop(S, q))
				cout << "栈为空" << endl;
			else
				cout << "出栈元素的值为：" << q << endl;
			system("pause");
			break;
		case 9:
			if (!StackTraverse(S))
				cout << "栈为空" << endl;
			else
				StackTraverse(S);
			system("pause");
			break;
		case 10:
			conversion();
			system("pause");
			break;
		case 11:
			return 0;
		}
		;
		system("cls");
	}
	return 0;
}

void InitStack(SqStack &S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(1);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{
	free(S.base);
	S.base = NULL;
	S.top = S.base;
	S.stacksize = 0;
}

void ClearStack(SqStack &S)
{
	S.top = S.base;
}

int StackEmpty(SqStack S)
{
	if (S.base == S.top && S.base != NULL)
		return 0;
	return 1;
}

int StackLength(SqStack S)
{
	return S.stacksize;
}

int GetTop(SqStack S, int &e)
{
	if (S.base == S.top) return 0;
	e = *(S.top - 1);
	return 1;
}

void Push(SqStack &S, int e)
{
	if (S.top - S.base > S.stacksize) {
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INIT_SIZE) * sizeof(SElemType));
		if (!S.base) exit(1);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INIT_SIZE;
	}
	*(S.top) = e;
	S.top++;
}

int Pop(SqStack &S, int &e)
{
	if (S.top == S.base) return 0;
	S.top--;
	e = *(S.top);
	return 1;
}

int StackTraverse(SqStack S)
{
	if (S.top == S.base) return 0;
	while (S.top != S.base) {
		S.top--;
		cout << *(S.top) << "\t";
	}
	return 0;
}

void conversion()
{
	SqStack S;

	InitStack(S);
	int m;
	cout << "请输入一个整数：" << endl;
	cin >> m;
	while (m >= 8) {
		Push(S, m % 8);
		m = m / 8;
	}
	Push(S, m);
	cout << "得到的八进制数为：";
	while (S.top != S.base) {
		S.top--;
		cout << *(S.top);
	}
	cout << endl;
}

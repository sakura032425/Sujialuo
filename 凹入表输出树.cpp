#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct Tree {
	char	data = 0;
	Tree *	child = NULL;
	Tree *	brother = NULL;
} *BTree;       //定义链表结构体
BTree T;        //定义根节点；
char c[50];     //存放结点字符数据
BTree a[50];    //存放结点地址；
int b[50];      //存放每个节点的度
int main()
{
	void NewTree(BTree & T);//声明函数
	void Show(BTree T, int n);

	cout << "请按层序输入结点元素：";
	cin >> c;
	cout << "请输入每个结点的度：";
	for (int i = 0; i < (int)strlen(c); i++)
		cin >> b[i];
	NewTree(T);
	Show(T, 0);

	return 0;
}
void NewTree(BTree &T)//生成树
{
	for (int i = 0; c[i]; i++) {
		BTree p = (BTree)malloc(sizeof(Tree));
		p->child = NULL;
		p->brother = NULL;
		p->data = c[i];
		a[i] = p;
	}//生成结点；
	for (int i = 0, k = 0; i < (int)strlen(c) - 1; k++)
		if (b[k]) {
			a[k]->child = a[++i];//第一个为孩子，地址存放在child中；
			b[k]--;
			while (b[k]) {
				a[i]->brother = a[i + 1];       //后续都为兄弟节点，存放在brother中
				i++;
				b[k]--;                         //每存放一个，度值减一，直到存完，度值为0位置
			}
		}
	T = a[0];               //把根节点地址赋给T
}
void Show(BTree T, int n)       //按凹入表形式输出数
{
	if (T) {
		for (int k = 0; k < n; k++)
			cout << " ";            //按照输出标准，在第几层输出几个空格
		cout << T->data << endl;        //输出data值
		Show(T->child, n + 1);          //递归调用，查找孩子的值，因为深度加一，传参为n+1
		Show(T->brother, n);            //孩子找完赵兄弟，因为在同层，传参为n；
	}
}

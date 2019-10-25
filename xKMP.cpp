#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int next[100] = { 0 };
	void Next(char *p, int *next_);
	int KMP(char *s, char *p, int *next);
	char s[100];
	char p[20];

	cout << "主串:";
	gets(s);                                //输入主串
	cout << "子串:";
	gets(p);                                //输入子串
	Next(p, next);                          //计算next数组
	cout << KMP(s, p, next) << endl;        //执行kmp并输出
}
void Next(char *p, int *next_)
{
	int k = -1, j = 0;

	next_[0] = -1;
	while (j < (int)strlen(p) - 1) {
		if (k == -1 || p[k] == p[j]) {
			k++;
			j++;//匹配相等 下标后移
			next_[j] = k;
		} else {
			k = next_[k];//不相等将k的值前移至上一个匹配成功的位置
		}
	}
}
void KMP(char *s, char *p, int *next)
{
	int i = 0, j = 0;

	while (i < (int)strlen(s)) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;                                    //匹配成功 下标后移
			if (j == (int)strlen(p)) {
				cout << i + 1 - j << " ";       //匹配成功，输出位置
				i = i + 1 - j;                  //向后移 准备进行下一次匹配
				j = 0;                          //从子串初始位置开始进行比较
			}
		} else {
			j = next[j];//匹配不成功，回退j的值
		}
	}
}

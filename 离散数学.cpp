#include <iostream>
#include <stdio.h>
using namespace std;
int Ksm(int a)                          // 快速幂
{
	int ans = 1, b = 2;

	while (a) {
		if ((a & 1) == 1)
			ans *= b;
		b *= b;
		a = a >> 1;
	}
	return ans;
}


int main()
{
	int a, b;                       // a变量个数  b存储总项数
	char q[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char c[100];                    // 存储真假值
	int f[50][50];                  // 存储真值表

	cout << "请输入变量个数:";
	cin >> a;
	b = Ksm(a);
	cout << endl;
	cout << endl;
	cout << "请输入" << b << "个字符:";
	getchar();
	gets(c);
	cout << endl;
	cout << endl;
	for (int i = 0; i < b; i++) {//真值表计算
		for (int j = a - 1; j >= 0; j--) {
			int s = i >> (a - j - 1);
			f[i][j] = s & 1;
		}
	}
	cout << "输出公式对应的真值表:" << endl;
	for (int i = 0; i < a; i++)
		cout << q[i] << "\t";
	cout << "#" << endl;
	for (int i = 0; i < 8 * a; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			if (f[i][j])
				cout << "T\t";
			else
				cout << "F\t";
		}
		cout << c[i] << endl;
	}
	for (int i = 0; i < 8 * a; i++)
		cout << "-";
	cout << endl;
	cout << "主析取范式输出" << endl;
	int m = 0;//主析取范式输出
	for (m = 0; m < b; m++)
		if (c[m] == 'T')
			break;
	if (c[m] == 'T') {
		cout << "(";
		int k = 0;
		if (f[m][k])
			cout << q[k];
		else
			cout << " !" << q[m];
		for (int j = 1; j < a; j++) {
			if (f[m][j])
				cout << " & " << q[j];
			else
				cout << " &!" << q[j];
		}
		cout << ")";
	}
	for (int i = m + 1; i < b; i++) {
		if (c[i] == 'T') {
			cout << " | (";
			int k = 0;
			if (f[i][k])
				cout << q[k];
			else
				cout << " !" << q[m];
			for (int j = 1; j < a; j++) {
				if (f[i][j])
					cout << " & " << q[j];
				else
					cout << " &!" << q[j];
			}
			cout << ")";
		}
	}
	cout << endl;
	cout << "主合取范式输出" << endl;
	int v = 0;//主合取范式输出
	for (v = 0; v < b; v++)
		if (c[v] == 'F')
			break;
	if (c[v] == 'F') {
		cout << "(";
		int k = 0;
		if (!f[v][k])
			cout << q[k];
		else
			cout << " !" << q[k];
		for (int j = 1; j < a; j++) {
			if (!f[v][j])
				cout << " | " << q[j];
			else
				cout << " |!" << q[j];
		}
		cout << ")";
	}
	for (int i = v + 1; i < b; i++) {
		if (c[i] == 'F') {
			cout << " & (";
			int k = 0;
			if (!f[i][k])
				cout << q[k];
			else
				cout << " !" << q[k];
			for (int j = 1; j < a; j++) {
				if (!f[i][j])
					cout << " & " << q[j];
				else
					cout << " &!" << q[j];
			}
			cout << ")";
		}
	}
	cout << endl;
	return 0;
}


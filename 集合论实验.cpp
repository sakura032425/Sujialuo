#include <iostream>
using namespace std;
int arr[100][100];
int a[2][100];
int main()
{
	int Reflexive(int n);
	int Symmetry(int n);
	int Transitivity(int n);
	int n, m;

	cout << "请输入矩阵范围:";
	cin >> m;
	cout << "请输入二元组个数:";
	cin >> n;
	cout << "请依次输入二元组:";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++)
			cin >> a[i][j];
		arr[a[i][0]][a[i][1]] = 1;
	}
	if (Reflexive(m))
		cout << "具有自反性" << endl;
	else
		cout << "具有反自反性" << endl;
	if (Symmetry(n))
		cout << "具有对称性" << endl;
	else
		cout << "具有反对称性" << endl;
	if (Transitivity(n))
		cout << "具有传递性" << endl;
	else
		cout << "不具有传递性" << endl;
	return 0;
}
int Reflexive(int m)
{
	for (int i = 0; i < m; i++)
		if (arr[i][i] == 0)
			return 0;
	return 1;
}
int Symmetry(int n)
{
	for (int i = 0; i < n; i++)
		if (arr[a[i][1]][a[i][0]] == 0)
			return 0;
	return 1;
}
int Transitivity(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][1] == a[j][0])
				if (arr[a[i][0]][a[j][1]] == 0)
					return 0;
		}
	}
	return 1;
}

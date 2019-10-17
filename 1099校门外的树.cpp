#include <iostream>
using namespace std;
int main()
{
	int m, n, k = 0;
	int a[600] = { 0 };

	cin >> m >> n;
	int b[10][2];
	for (int i = 0; i < n; i++)
		for (int d = 0; d < 2; d++)
			cin >> b[i][d];
	for (int i = 0; i < n; i++) {
		for (int d = b[i][0]; d <= b[i][1]; d++)
			if (a[d] == 0)
				a[d] = 1;
	}
	for (int i = 0; i < m; i++)
		if (a[i])
			k++;
	cout << m + 1 - k << endl;
	return 0;
}

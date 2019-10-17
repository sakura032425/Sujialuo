#include <iostream>
using namespace std;
int main()
{
	int arr[100];

	for (int a = 0, i = 0; i < 100; i++) {
		a += 2;
		arr[i] = a;
	}
	int zu[2][2];
	for (int i = 0; i < 2; i++)
		for (int a = 0; a < 2; a++)
			cin >> zu[i][a];
	for (int i = 0; i < 2; i++) {
		int a;
		for (a = 0; a < zu[i][0] - (zu[i][0] % zu[i][1]); a += zu[i][1]) {
			int m;
			int k;
			for (m = 0, k = 0; k < zu[i][1]; k++)
				m += arr[a + k];
			cout << m / k << " ";
		}
		if (a >= zu[i][0] - (zu[i][0] % zu[i][1])) {
			int m = 0;
			int k;
			for (k = 0; a < zu[i][0]; k++, a++)
				m += arr[a];
			cout << m / k;
		}
		cout << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	char c[500];
	int a, add = 0, d = 0;

	gets(c);
	cin >> a;
	int q[26] = { 0 };
	int l = 0;
	for (; c[l]; l++)
		;
	for (int i = 0; i < l; i++)
		q[c[i] - 'a']++;
	int n = 0;
	for (; n < 26 && add < a; n++)
		add += q[n];
	for (int i = 0; i < l; i++) {
		if (c[i] < 'a' + n - 1) {
			cout << c[i];
		} else if (c[i] == 'a' + n - 1 && d < q[n - 1] - (add - a)) {
			cout << c[i];
			d++;
		}
	}
	return 0;
}

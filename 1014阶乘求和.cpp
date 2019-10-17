#include <iostream>
using namespace std;
int main()
{
	long long int a, b = 1, s = 0;

	cin >> a;
	for (int i = 1; i <= a; i++) {
		b *= i;
		s += b
	}
	cout << s << endl;
	return 0;
}

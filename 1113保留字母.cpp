#include <iostream>
using namespace std;
int main()
{
	char c[100];

	cin >> c;
	for (int i = 0; c[i]; i++)
		if (((c[i] >= 'a') && (c[i] <= 'z')) || ((c[i] >= 'A') && (c[i] <= 'Z')))
			cout << c[i];
	cout << endl;
	return 0;
}

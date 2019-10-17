#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}


int main()
{
	for (int i = 1; i < 40; i++)
		if (gcd(i, 40) == 1)
			cout << i << "/40,";
	cout << endl;
	return 0;
}

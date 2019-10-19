#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int next[100] = { 0 };
	void Next(char *p, int *next_);
	int KMP(char *s, char *p, int *next);
	char s[100] = "asdfwerabcsdfwerlkjhf";
	char p[20];

	cout << "Ö÷´®:";
	puts(s);
	cout << "×Ó´®:";
	gets(p);
	Next(p, next);
	cout << KMP(s, p, next) << endl;
}
void Next(char *p, int *next_)
{
	int k = -1, j = 0;

	next_[0] = -1;
	while (j < (int)strlen(p) - 1) {
		if (k == -1 || p[k] == p[j]) {
			k++;
			j++;
			next_[j] = k;
		} else {
			k = next_[k];
		}
	}
}
int KMP(char *s, char *p, int *next)
{
	int i = 0, j = 0;

	while (i < (int)strlen(s) && j < (int)strlen(p)) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}
	if (i < (int)strlen(s))
		return i - j + 1;
	else
		return -1;
}

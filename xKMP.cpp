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

	cout << "����:";
	gets(s);                                //��������
	cout << "�Ӵ�:";
	gets(p);                                //�����Ӵ�
	Next(p, next);                          //����next����
	cout << KMP(s, p, next) << endl;        //ִ��kmp�����
}
void Next(char *p, int *next_)
{
	int k = -1, j = 0;

	next_[0] = -1;
	while (j < (int)strlen(p) - 1) {
		if (k == -1 || p[k] == p[j]) {
			k++;
			j++;//ƥ����� �±����
			next_[j] = k;
		} else {
			k = next_[k];//����Ƚ�k��ֵǰ������һ��ƥ��ɹ���λ��
		}
	}
}
void KMP(char *s, char *p, int *next)
{
	int i = 0, j = 0;

	while (i < (int)strlen(s)) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;                                    //ƥ��ɹ� �±����
			if (j == (int)strlen(p)) {
				cout << i + 1 - j << " ";       //ƥ��ɹ������λ��
				i = i + 1 - j;                  //����� ׼��������һ��ƥ��
				j = 0;                          //���Ӵ���ʼλ�ÿ�ʼ���бȽ�
			}
		} else {
			j = next[j];//ƥ�䲻�ɹ�������j��ֵ
		}
	}
}
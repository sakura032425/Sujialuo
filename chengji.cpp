#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	char m[30];
	FILE *fp;

	if ((fp = fopen("d:\\my.txt", "r+")) == NULL) {
		printf("can not open file\n");
		exit(0);
	}
	for (int i = 0; i < 30; i++)
		fread(&m[i], 1, 1, fp);
	for (int i = 0; i < 30; i += 3)
		m[i]++;
	rewind(fp);
	fputs(m, fp);
	fclose(fp);
	return 0;
}

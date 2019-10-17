//1093
#include<iostream>
using namespace std;
int main()
{
    char a[100];
    char b[100];
    gets(a);
    int i,n;
    for(i=0;a[i]!='\0';i++)
    {

    }
    i--;
    for(n=0;i>=0;i--,n++)
    {
        b[n]=a[i];
    }
    b[n]='\0';
    puts(b);
    return 0;
}

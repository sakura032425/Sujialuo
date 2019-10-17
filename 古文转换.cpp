#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[1000],b[1000][1000];
    int r,l,k=0;
    cin>>r;
    getchar();
    gets(a);
    int len=strlen(a);
    l=len/r;
    if(len%r) l++;
    for(int m=l-1;m>=0;m--)
    {
        for(int n=0;n<r;n++,k++)
        {
            if(k<len) b[n][m]=a[k];
            else b[n][m]=' ';
        }
    }
    for(int m=0;m<r;m++)
    {
        for(int n=0;n<l;n++)
        cout<<b[m][n];
        cout<<endl;
    }
    return 0;
}

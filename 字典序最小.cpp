#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char c[500];
    char c1[500];
    int a,k=0;
    gets(c);
    cin>>a;
    int l=strlen(c);
    for(int i=0;i<a;i++)
    {
        for(int j=k+1,m=128;j<=l-(a-i);j++)
        {
            if(c[j]<m)
            {
                m=c[j];
                k=j;
            }
        }
        c1[i]=c[k];
    }
    puts(c1);
    return 0;
}

#include<iostream>
using namespace std;
int main()
{
    int a[3000]={0};
    for(int i=1;i<1400;i++)
    {
        if(a[i-1])
        continue;
        int m=0,n=0;
        for(int j=1;j<i;j++)
        if(i%j==0)
        m+=j;
        for(int k=1;k<m;k++)
        if(m%k==0)
        n+=k;
        if(n==i&&m!=i)
        cout<<"("<<i<<","<<m<<")";
        a[m-1]=1;
    }
    return 0;
}

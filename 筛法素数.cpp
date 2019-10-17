//1084
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[500];
    for(int i=0;i<500;i++)
    a[i]=1;
    for(int i=2;i<sqrt(n);i++)
    {
        for(int b=i+1;b<=n;b++)
        {
            if(b%i==0)
            {
                a[b-1]=0;
            }
        }
    }
    for (int i=1;i<n-1;i++)
    {
        if(a[i])
        {
            cout<<i+1<<endl;
        }
    }
    return 0;
}

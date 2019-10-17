//1097
#include<iostream>
using namespace std;
int main()
{
    int n,k=0,r=1,a;//k记录行下标差,r记录行第一个
    cin>>n;
    for(r=1;k<n;k++)
    {
        r+=k;
        cout<<r<<" ";
        for(int m=k+2,a=r;m<=n;m++)
        {
            cout<<a+m<<" ";
            a+=m;
        }
        cout<<endl;
    }
    return 0;
}

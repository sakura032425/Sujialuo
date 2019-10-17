#include<iostream>
using namespace std;
int main()
{
    int a,c;
    int m[10];
    cin>>a;
    for(c=0;a;c++)
    {
        m[c]=a%10;
        a/=10;
    }
    cout<<c<<endl;
    for(int i=c-1;i>=0;i--)
    cout<<m[i]<<' ';
    cout<<endl;
    for(int i=0;i<c;i++)
    cout<<m[i];
    cout<<endl;
    return 0;
}

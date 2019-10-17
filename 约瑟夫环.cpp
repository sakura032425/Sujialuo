#include<iostream>
using namespace std;
int main()
{
    int i=0,b=1,n=0,x,y;
    int a[100]={0};
    cin>>x>>y;
    for(;n<x-1;i++,i%=x)
    {
        if(a[i])
        continue;
        else if(b%y==0)
        {
            a[i]=1;
            n++;
            cout<<i+1<<" ";
        }
        b++;
    }
    cout<<endl;
    for(int j=0;j<x;j++)
    if(a[j]==0)
    cout<<j+1;
    return 0;
}

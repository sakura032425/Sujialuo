#include<iostream>
using namespace std;
int sushu(int a)
{
    for(int i=2;i<a/2;i++)
    if(a%i==0)
    return 0;
    return 1;
}
int main()
{
    int n,x=0,y=0;
    cin>>n;
    if(n<6)
    {
        cout<<"bukefenjie"<<endl;
        return 0;
    }
    else
    {
        int i=4;
        for(;i<=n/2;i++)
        if(sushu(i)&&sushu(n-i))
        {
            x=i;
            y=n-i;
            break;
        }
        if(i>n/2+1)
        {
            cout<<"bukefenjie"<<endl;
            return 0;
        }
        for(int j=2;j<=x/2;x++)
        if(sushu(j)&&sushu(x-j))
        {
            cout<<j<<" "<<x-j<<" ";
            break;
        }
        for(int j=2;j<=y/2;j++)
        if(sushu(j)&&sushu(x-j))
        {
            cout<<j<<" "<<y-j<<endl;
            break;
        }
    }
    return 0;
}

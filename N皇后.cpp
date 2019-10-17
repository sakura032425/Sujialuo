#include<iostream>
#include<cmath>
using namespace std;
int queen[8];
int x=0;
void shuchu()
{
    for(int i=0;i<8;i++)
    {
        cout<<"("<<i<<","<<queen[i]<<")";
    }
    cout<<endl;
}
int check(int n)
{
    for(int i=0;i<n;i++)
    {
        if(queen[i]==queen[n]||queen[n]+n==queen[i]+i||abs(queen[n]-queen[i])==abs(i-n))
        return 0;
    }
    return 1;
}
void fangzhi(int n)
{
    for(int i=0;i<8;i++)
    {
        queen[n]=i;
        if(check(n))
        {
            if(n==7)
            {
                shuchu();
                x++;
            }
            else
            fangzhi(n+1);
        }
    }
}
int main()
{
    int n=0;
    fangzhi(n);
    cout<<x<<endl;
    return 0;
}

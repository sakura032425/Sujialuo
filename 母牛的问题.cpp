//1104
#include<iostream>
using namespace std;
int main()
{
    int a[60]={1,2,3,4};
    for(int i=4;i<56;i++)
    {
        a[i]=a[i-1]+a[i-3];
    }
    int n;
    while(1)
    {
        cin>>n;
        if(n==0)
        break;
        cout<<a[n-1]<<endl;
    }
    return 0;
}

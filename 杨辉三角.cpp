#include<iostream>
using namespace std;
int main()
{
    int a[100]={0,1,0},b[100]={0};
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int m=1;m<=n-i;m++)
        {
            cout<<" ";
        }
        for(int m=1;m<=i;m++)
        {
            printf("%d ",a[m]);
        }
        for(int m=0;m<i+2;m++)
        {
            b[m+1]=a[m]+a[m+1];
        }
        for(int c=1;c<i+3;c++)
        {
            a[c]=b[c];
        }
        cout<<endl;
    }
    return 0;
}

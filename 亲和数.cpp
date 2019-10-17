//1157
#include<iostream>
using namespace std;
int main()
{
    int arr[20][2];
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int a=0;a<2;a++)
        {
            cin>>arr[i][a];
        }
    }
    for(int i=0;i<n;i++)
    {
        int flag1=0,flag2=0,a=0;
        for(m=1;m<arr[i][0];m++)
        {
            if(arr[i][0]%m==0)
            {
                a+=m;
            }
        }
        if(a==arr[i][1])
        flag1=1;
        for(m=1,a=0;m<arr[i][1];m++)
        {
            if(arr[i][1]%m==0)
            {
                a+=m;
            }
        }
        if(a==arr[i][0])
        flag2=1;
        if(flag1&&flag2)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}

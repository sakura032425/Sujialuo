#include<iostream>
using namespace std;
int main()
{
    int n,x,y,min=10000,max=0,flag=1,k,m=0;
    cin>>n;
    int a[10000];
    for(int i=0;i<10000;i++)
    a[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(a[x])
        m=1;
        a[x]=i;
        a[y-1]=i;
        if(x<min)
        min=x;
        if(y>max)
        max=y-1;
    }
    if(m)
    {
        cout<<"chongtu";
        return 0;
    }
    k=a[min];
    for(int i=min;i<=max;i++)
    {
        if(a[i]&&a[i]!=k&&flag==1)
        {
            cout<<"chongtu"<<endl;
            return 0;
        }
        else if(a[i]&&a[i]!=k&&flag==0)
        {
            k=a[i];
            flag=1;
        }
        else if(a[i]==k)
        flag=0;
    }
    cout<<"buchongtu"<<endl;
    return 0;
}

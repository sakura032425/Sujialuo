#include<iostream>
using namespace std;
int arr[10][10];
int juli[100]={0},j=0,x=100;
int n,m,k,q,l=0,d=0;
int main()
{
    void run(int a);
    cin>>n>>m>>k>>q;
    for(int i=0;i<m;i++)
    {
        for(int i1=0;i1<3;i1++)
        {
            cin>>arr[i][i1];
        }
    }
    run(k);
    if(juli[0]==0)
    cout<<"lei shen ku l"<<endl;
    for(int i=0;i<j-1;i++)
    {
        if(juli[j]<x)
        x=juli[j];
    }
    cout<<x<<endl;
}
void run(int a)
{
    d=0;
    for(int i=0;i<n;i++)
    if(arr[i][0]==a)
    {
        l++;
        d+=arr[i][2];
        if(arr[i][1]!=q)
        {
            run(arr[i][1]);

        }
        else
        {
            juli[j]=d;
            j++;
        }
    }
}

#include<iostream>
using namespace std;
int main()
{
    int a[100][100],t;
    cin>>t;
    a[0][0]=1;
    int x=0,y=1,k=2;
    while(1)
    {
        while(y>=0) a[x++][y--]=k++;
        y++;
        if(x==t) break;
        while(x>=0) a[x--][y++]=k++;
        x++;
        if(y==t) break;
    }
    for(int m=0;m<t;m++)
    {
        for(int n=0;n<t-m;n++)
        cout<<a[m][n]<<' ';
        cout<<endl;
    }
    return 0;
}

//1115
#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[10][2];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int m=0;m<2;m++)
        {
            cin>>a[i][m];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(;a[i][1];a[i][1]--)
        {
            for(int c=1;c<a[i][0];c++)//c控制行数
            {
                for(int m=1;m<=a[i][0];m++)
                {
                    if(m==c||m==a[i][0]-c+1)
                    cout<<"X";
                    else
                    cout<<" ";
                }
                cout<<endl;
            }
        }
        for(int d=1;d<=a[i][0];d++)
        {
            if(d==1||d==a[i][0])
            cout<<"X";
            else
            cout<<" ";
        }
        cout<<endl;
        cout<<endl;
    }

    return 0;
}

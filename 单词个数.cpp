#include<iostream>
using namespace std;
int main()
{
    int flag=0,d=0;
    char a[50];
    gets(a);
    for(int i=0;a[i];i++)
    {
        if(a[i]==' ')
        flag=0;
        else if(flag==0)
        {
            d++;
            flag=1;
        }
    }
    cout<<d<<endl;
    return 0;
}

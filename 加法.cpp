#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[100],b[100],c[100]={'\0'},d;
    gets(a);
    gets(b);
    int a1=strlen(a)-1;
    int b1=strlen(b)-1;
    int k=(a1>b1?a1:b1);
    for(int i=0;i<=a1/2;i++)
    {
        char ch;
        ch=a[a1-i];
        a[a1-i]=a[i];
        a[i]=ch;
    }
    for(int i=0;i<=b1/2;i++)
    {
        char ch;
        ch=b[b1-i];
        b[b1-i]=b[i];
        b[i]=ch;
    }
    for(int i=0;i<k;i++)
    {
        if((d=a[i]+b[i]+c[i]-48)>57)
        {
            c[i]+=(d-10-c[i]);
            c[i+1]++;
        }
        else
        {
            if(a[i]<48)
            a[i]+=48;
            if(b[i]<48)
            b[i]+=48;
            c[i]+=(a[i]+b[i]-48);
        }
    }
    if(a[k]+b[k]-48>57)
    {
        c[k]+=(a[k]+b[k]-48-10);
        c[++k]=49;
    }
    else
    {
        if(a[k]<48)
        a[k]+=48;
        if(b[k]<48)
        b[k]+=48;
        c[k]+=(a[k]+b[k]-48);
    }
    for(;k>=0;k--)
    {
        cout<<c[k];
    }
    cout<<endl;
    return 0;
}

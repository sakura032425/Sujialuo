#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a;
    for(a=100;a<1000;a++)
    {
        int m=pow(a%10,3)+pow(a/10%10,3)+pow(a/100,3);
        if(m==a)
        cout<<a<<endl;
    }
    return 0;
}

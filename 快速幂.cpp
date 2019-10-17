#include <iostream>
using namespace std;
typedef long long int LL;
LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1==1)
        ans=(ans*a)%1000000007;
        a=(a*a)%1000000007;
        b=b>>1;
    }
    return ans;
}

int main()
{
    int i=0;
    int a[1000];
    LL N;
    while(1)
    {
        cin>>N;
        if(N==0)
        break;
        a[i]=(quick_mod(4, N-1) + quick_mod(2, N-1))%1000000007;
        i++;
    }
    for(int c=0;c<i;c++)
    {
        cout<<a[c]<<endl;;
    }
    // LL m;
    // m=(quick_mod(4, 100-1) + quick_mod(2, 100-1))%1000000007;
    // for(LL k=101;k<100000;k++)
    // {
    //     LL d=(quick_mod(4, k-1) + quick_mod(2, k-1))%1000000007;
    //     if(d==m)
    //     cout<<k<<endl;
    // }
    // while(1)
    // {
    //     scanf("%lld",&N);
    //     int ans;
    //     if(N==0)
    //     break;
    //     if(N>100)
    //     {
    //         LL x=N%100;
    //         LL y=N/100;
    //         ans = (quick_mod(499445072, y) + quick_mod(976371285, y))%1000000007;
    //         ans*=((quick_mod(4, x-1) + quick_mod(2, x-1))%1000000007)%1000000007;
    //
    //     }
    //     else
    //     ans=(quick_mod(4, N-1) + quick_mod(2, N-1))%1000000007;
    //     a[i]=ans;
    //     i++;
    // }
    // for(int c=0;c<i;c++)
    // cout<<a[c]<<endl;
    // for(int i=1;i<99999;i++)
    // for(int j=i+1;j<99999;j++)
    // if(b[i]==b[j])
    // {
    //     cout<<i<<" "<<j<<endl;
    // }
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   int n, k;

   cin >> n >> k;
   int M = pow(10, k);
   int m = n;
   n %= M;
   for (int i = 0; i < n; i++)
   {
      m *= m;
      m %= M;
      if (m == n)
      {
         cout << i << endl;
         return 0;
      }
   }
   cout << -1 << endl;
   return 0;
}

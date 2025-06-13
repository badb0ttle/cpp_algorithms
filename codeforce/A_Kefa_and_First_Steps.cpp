/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=1e5+1;
int dp[mx],n;
void work()
{
   std::cin>>n;
   int a[n];
   std::fill(dp,dp+n,1);
   for(int&i:a)std::cin>>i;
   for(int i=0;i<n-1;++i)
   {
        if(a[i]<=a[i+1])dp[i+1]=dp[i]+1;
   }
   std::cout<<*std::max_element(dp,dp+n)<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    //std::cin>>_;
    while(_--)work();
    return 0;
}
/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=1e2+1;
int n,a[mx];
int dp[mx][2];
void work()
{
   std::cin>>n;
   memset(dp,0,sizeof(dp));
   for(int i=1;i<=n;++i)std::cin>>a[i];
    dp[1][0]=0;
    dp[1][1]=a[1];
    int t=a[1];
   for(int i=2;i<=n;++i)
   {
    dp[i][1]=std::max(a[i],dp[i-2][1]);
    dp[i][0]=dp[i-1][1];
   }
   int ra=dp[n][1]+(n+1)/2;
   int rb=dp[n][0]+n-(n+1)/2;
   std::cout<<std::max(ra,rb)<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
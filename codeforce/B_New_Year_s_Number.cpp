/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=1e6+1;
int dp[mx],n;
void work()
{
   std::cin>>n;
   memset(dp,0,sizeof(dp));
   for(int i=0;i<=n;++i)
   {
    if(i-dp[i-2020]-2020==0)dp[i]=i;
    if(i-dp[i-2021]-2021==0)dp[i]=i;
   }
   std::cout<<(dp[n]?"YES":"NO")<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
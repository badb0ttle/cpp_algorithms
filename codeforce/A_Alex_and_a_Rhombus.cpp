/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=101;
int dp[mx];
void work()
{
   int n;
   std::cin>>n;
    dp[1]=1;
    for(int i=2;i<=n;++i)
    {
        dp[i]=dp[i-1]+(i)+2*(i-1)+(i-2);
    }
    std::cout<<dp[n]<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    //std::cin>>_;
    while(_--)work();
    return 0;
}
/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 21;
int n, m;
char mp[mx][mx];
int dp[mx];
void work()
{
    
    std::cin >> n >> m;
    std::fill(dp+1,dp+1+m,0);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> mp[i][j];
for(int i=1;i<=m;++i)
{
     
    for(int j=1;j<=n;++j)
    {
        if(dp[i-1]==0&&mp[j][i]=='v')
        {dp[i]=dp[i-1]+1;break;}
        else if(dp[i-1]==1&&mp[j][i]=='i')
        {dp[i]=dp[i-1]+1;break;}
        else if(dp[i-1]==2&&mp[j][i]=='k')
        {;dp[i]=dp[i-1]+1;break;}
        else if(dp[i-1]==3&&mp[j][i]=='a')
        {dp[i]=dp[i-1]+1;break;}
        
    }
    dp[i] = std::max(dp[i],dp[i - 1]);
}
    
    if(dp[m]==4)std::cout<<"YES\n";
    else
    std::cout << "NO\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    while (_--)
        work();
    return 0;
}
/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 101;
int n, m;
std::string s;
int dp[mx];
void work()
{
    std::cin >> n >> m ;
    std::cin>>s;
    s='$'+s;
    std::fill(dp + 1, dp + 1 + n, INT_MAX);
    dp[1] = 0;//在起点时不用消耗代价
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i] == INT_MAX || s[i] != '1')//前一个点和当前点可达
            continue;
        for (int j = 1; j <= m && j + i <= n; ++j)//枚举步长
        {
            int pos=j+i;
            if(s[pos]=='1')dp[pos]=std::min(dp[pos],dp[i]+1);
        }
    }
if (dp[n] == INT_MAX)
    std::cout << "-1\n";
else
    std::cout << dp[n] << '\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    // std::cin>>_;
    while (_--)
        work();
    return 0;
}
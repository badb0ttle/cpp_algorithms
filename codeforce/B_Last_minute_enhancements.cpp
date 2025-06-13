/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 1e5 + 1;
int n;
int a[mx];
int vis[mx << 1];
int dp[mx];
void work()
{
    std::cin >> n;
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        vis[a[i]]++;//初始化记录每个元素出现次数
    }
    dp[n + 1] = 0;
    for (int i = n; i >= 1; --i)//贪心从最大的元素开始
    {
        if (!vis[a[i] + 1])//如果能变成不存在的数字绝对变了不亏
        {
            vis[a[i] + 1] ++;
            vis[a[i]]--;
            dp[i] = dp[i + 1] + 1;
        }
        else
        {
            if(vis[a[i]]>1)//相同元素只处理最后一个其他不变
            {
                vis[a[i]]--;    
                dp[i] = dp[i + 1];
            }
            else dp[i]=dp[i+1]+1;
        }
    }
    std::cout << dp[1] << '\n';
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
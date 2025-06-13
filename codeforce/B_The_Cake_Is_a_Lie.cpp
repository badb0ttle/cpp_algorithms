/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 101;
int dp[mx][mx], n, m, k;
void work()
{
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = 1e9;

    dp[1][1] = 0;
    dp[1][1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i > 1)
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + j);
            if (j > 1)
                dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + i);
        }
    }
    if (dp[n][m] == k)
        std::cout << "YES\n";
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
/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 1e2 + 1;
struct p
{
    int x, y;
};
char mp[3][mx];
int n;
bool dp[3][mx];
void work()
{
    std::cin >> n;
    memset(dp,0,sizeof(dp));
     for (int i = 1; i <= 2; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> mp[i][j];
    dp[1][1] = 1;
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            
        }
    }
    std::cout << (dp[2][n] ? "YES\n" : "NO\n");
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
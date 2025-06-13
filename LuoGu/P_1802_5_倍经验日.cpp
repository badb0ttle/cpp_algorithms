/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx = 1e3 + 1;
ll n, m;
ll l[mx], w[mx], v[mx], dp[mx];
void work()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> w[i] >> v[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= v[i]; --j)
            dp[j] = max(dp[j] + l[i], dp[j - v[i]] + w[i]);
        for (int j = v[i] - 1; j >= 0; --j)
            dp[j] += l[i];
    }
    cout << dp[m] * 5 << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}
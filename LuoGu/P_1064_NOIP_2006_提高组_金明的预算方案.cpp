/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx = 4e4 + 1;
int n, m, v[mx][3], p[mx][3], q[mx];
vector<int> val;
vector<int> jl;
int dp[mx];
void work()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> v[i][0] >> p[i][0] >> q[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        if (q[i] != 0)
        {
            for (int j = 0; j <= 2; ++j)
            {
                if (v[i][j] == 0)
                {
                    v[i][j] = v[q[i]][j];
                    p[i][j] = p[i][0] + p[q[i]][j];
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (q[mx] != '0')
        {
            val.push_back(v[i][0]);
            jl.push_back(p[i][0]);
            for (int j = 1; j <= 2; ++j)
            {
                if (v[i][j] == 0)
                    break;
                if (j == 2)
                {
                    val.push_back(v[i][0] + v[i][2]);
                    jl.push_back(p[i][0] + p[i][2]);
                    val.push_back(v[i][0] + v[i][1] + v[i][2]);
                    jl.push_back(p[i][0] + p[i][1] + p[i][2]);
                }
                else if (j == 1)
                {
                    val.push_back(v[i][0] + v[i][1]);
                    jl.push_back(p[i][0] + p[i][1]);
                }
            }
        }
    }
    fill(begin(dp), end(dp), INT_MAX);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < val.size(); ++i)
        {
            if (i - val[j] >= 0)    dp[i] = max(dp[i], dp[i - val[j]] + jl[j]);
        }
    }
    cout << dp[n] << '\n';
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
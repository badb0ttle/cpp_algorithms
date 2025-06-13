/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
int n, m, cnt, ans;
bool f;
vector<vector<int>> a;
vector<vector<bool>> vis;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (a[x][y] >= 2 && a[x][y] <= 9)
        f = 1;
    for (int i = 0; i < 4; ++i)
    {
        int ex = x + dx[i], ey = y + dy[i];
        if (ex < 0 || ey < 0 || ey >= m || ex >= n || vis[ex][ey] || a[ex][ey] == 0)
            continue;

        vis[ex][ey] = 1;
        dfs(ex, ey);
    }
}
void work()
{
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    vis.resize(n, vector<bool>(m, 0));
    char c;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> c;
            int tt=c-'0';
            a[i][j]=tt;
        }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!vis[i][j] && a[i][j] != 0)
            {
                f = 0;
                dfs(i, j);
                cnt++;
                if (f)
                    ans++;
            }
        }
    }
    cout << cnt << ' ' << ans << '\n';
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
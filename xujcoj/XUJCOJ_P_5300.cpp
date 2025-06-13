/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx = 1e3 + 1;
int mp[mx][mx];
int m;
struct p
{
    int x, y, a;
};
int dis(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
void work()
{
    memset(mp, 0, sizeof(mp));
    cin >> m;
    vector<p> v(m + 1);
    for (int i = 1; i <= m; ++i)
        cin >> v[i].x >> v[i].y >> v[i].a;
    int ans = 0;
    for (int i = 1; i < 1001; ++i)
        for (int j = 1; j < 1001; ++j)
            for (int k = 1; k <= m; ++k)
                mp[i][j] += max(0, v[k].a - dis(i, j, v[k].x, v[k].y));

    for (int i = 1; i < mx; ++i)
        for (int j = 1; j < mx; ++j)
            ans = max(ans, mp[i][j]);
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}
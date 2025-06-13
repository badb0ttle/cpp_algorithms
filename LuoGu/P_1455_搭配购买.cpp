/*🫵😉👍*/
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <string.h>
#include <string>
#include <stdio.h>
#include <deque>
#include <numeric>
using namespace std;
#define ll long long
#define lll __uint128_t
#define ld long double
#define ull unsigned long long
#define re register
#define il inline
#define fi first
#define SZ(x) ((int)(x).size())
#define se second
#define all(v) v.begin(), v.end()
#define pb push_back
#define lowbit(x) (x & -x)
#define fixed(x) fixed << setprecision(x)
#define lcm(x, y) x *y / __gcd(x, y)
#define endl "\n"
#define io ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const ll N = 1e4 + 100, M = 1e6 + 10, base = 13331, mod = 1e9 + 7;
const ull INF = 1e18;
const double pie = acos(-1), eps = 1e-8;
int dir[] = {0, 1, 0, -1, 0};
const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, -1, 0, 1, -1};
typedef pair<ll, ll> PAIR;
int n, m, w, u, v;
PAIR LOL[N];
map<int, int> mp;
map<int, int> mp1;
int pre[N], dp[N];
int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void merge(int x, int y)
{
    pre[root(x)] = root(y);
}
void solve()
{
    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i)
        cin >> LOL[i].first >> LOL[i].second;
    for (int i = 1; i <= n; ++i)
        pre[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        merge(u, v);
    }
    for (int i = 1; i <= n; ++i)
    {
        mp[root(i)] += LOL[i].second;
        mp1[root(i)] += LOL[i].first;
    }
    vector<int> cc, vv;
    for (auto i : mp)
        cc.pb(i.second);
    for (auto i : mp1)
        vv.pb(i.second);
    for (int i = 0; i < SZ(cc); ++i)
    {
        for (int j = w; j >= vv[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - vv[i]] + cc[i]);
        }
    }
    cout << dp[w] << '\n';
}
signed main()
{
    io;
    ll _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
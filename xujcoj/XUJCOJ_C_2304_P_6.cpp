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
#define se second
#define all(v) v.begin(), v.end()
#define pb push_back
#define lowbit(x) (x & -x)
#define fixed(x) fixed << setprecision(x)
#define lcm(x, y) x *y / __gcd(x, y)
#define endl "\n"
#define io ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const ll N = 1e3 + 100, M = 1e6 + 10, base = 13331, mod = 1e9 + 7;
const ull INF = 1e18;
const double pie = acos(-1), eps = 1e-8;
int dir[] = {0, 1, 0, -1, 0};
const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, -1, 0, 1, -1};
typedef pair<ll, ll> PAIR;
struct node
{
    int v, fa, lc, rc, dep;
} t[N];
int root = 0, idx = 0;
map<int, int> mp;
void ins(int &u, int v, int fa, int dep)
{
    if (!u)
    {
        u = ++idx;
        t[u] = {v, fa, 0, 0, dep};
        mp[v] = u;
        return;
    }
    if (v < t[u].v)
        ins(t[u].lc, v, u, dep + 1);
    else
        ins(t[u].rc, v, u, dep + 1);
}
int getxd(int u)
{
    int f = t[u].fa;
    if (!f)
        return 0;
    if (t[f].lc == u && t[f].rc)
        return t[t[f].rc].v;
    if (t[f].rc == u && t[f].lc)
        return t[t[f].lc].v;
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int &i : a)
        cin >> i;
    for (int i : a)
        ins(root, i, 0, 1);
    sort(a, a + n);
    for (int i : a)
    {
        int tmp = mp[i];
        cout << t[tmp].v << ' ' << (t[tmp].fa ? t[t[tmp].fa].v : 0) << ' ' << getxd(tmp) << ' ' <<
         (t[tmp].lc ? t[t[tmp].lc].v : 0) << ' ' << (t[tmp].rc ? t[t[tmp].rc].v : 0) <<
          ' ' << t[tmp].dep << '\n';
    }
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
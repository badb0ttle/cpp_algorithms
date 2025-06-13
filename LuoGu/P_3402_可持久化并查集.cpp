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
const ll N = 1e5 + 100, M = 1e6 + 10, base = 13331, mod = 1e9 + 7;
const ull INF = 1e18;
const double pie = acos(-1), eps = 1e-8;
int dir[] = {0, 1, 0, -1, 0};
const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, -1, 0, 1, -1};
typedef pair<ll, ll> PAIR;
PAIR stk[N];
int pre[N], sz[N], top, n, m, op;
deque<PAIR> qe;
int find(int x) { return pre[x] == x ? x : find(pre[x]); }
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    if (fx > fy)
        swap(fx, fy);
    stk[++top] = {fx, fy};
    pre[fx] = fy, sz[fy] += sz[fx];
}
void undo()
{
    if (!top)
        return;
    auto [x, y] = stk[top--];
    sz[y] -= sz[x];
    pre[x] = x;
}
bool same(int x, int y)
{
    return find(x) == find(y);
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        pre[i] = i, sz[i] = 1;
    int t = 0, cnt = 0;
    while (m--)
    {
        cin >> op;
        t++;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            merge(x, y);
            cnt++;
            qe.push_front({cnt, t});
        }
        else if (op == 2)
        {
            int k;
            cin >> k;
            while (!qe.empty() && qe.back().second >= k)
            {   
                undo();
                qe.pop_back();
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << same(x, y) << '\n';
        }
        
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
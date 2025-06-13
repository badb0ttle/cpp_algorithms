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
string a, b;
string add(string a, string b)
{
    string res="";
    int n = a.size(), f = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int t = (a[i] - 'a') + (b[i] - 'a') + f;
        res += (char)(t % 26 + 'a');
        f = t / 26;
    }
    if (f)
        res += (char)(f + 'a');
    reverse(res.begin(), res.end());
    return res;
}
string tr2(string a)
{
    string res="";
    int  f = 0;
    for (int i = 0; i < (int)a.size(); ++i)
    {
        int t = f * 26 + (a[i] - 'a');
        res += (char)((t >> 1) + 'a');
        f = t % 2;
    }
    return res;
}
//999+999=1998/2=999
//zzz
//zzz

void solve()
{
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    string t = add(a, b);
    t=tr2(t);
    if((int)(t.size())!=(int)(a.size()))
    {
        t=t.substr(1);
    }
    cout<<t<<'\n';
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
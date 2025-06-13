/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 1e6 + 1;
const ll inf = 2e18;
ll a[mx], tmx[mx << 2], tmn[mx << 2], n, l;
void pushup(ll v)
{
    tmx[v] = max(tmx[v << 1], tmx[v << 1 | 1]);
    tmn[v] = min(tmn[v << 1], tmn[v << 1 | 1]);
}
void build(ll s = 1, ll e = n, ll o = 1)
{
    if (s == e)
        return tmx[o] = tmn[o] = a[s], void();
    ll mid = (s + e) >> 1;
    build(s, mid, o << 1), build(mid + 1, e, o << 1 | 1);
    pushup(o);
}
ll querymx(ll l, ll r, ll s = 1, ll e = n, ll o = 1)
{
    if (l <= s && r >= e)
    {
        return tmx[o];
    }
    ll mid = (s + e) >> 1;
    ll res = -inf;
    if (mid >= l)
        res = max(res, querymx(l, r, s, mid, o << 1));
    if (mid + 1 <= r)
        res = max(res, querymx(l, r, mid + 1, e, o << 1 | 1));
    return res;
}
ll querymn(ll l, ll r, ll s = 1, ll e = n, ll o = 1)
{
    if (l <= s && r >= e)
    {
        return tmn[o];
    }
    ll mid = (s + e) >> 1;
    ll res = inf;
    if (mid >= l)
        res = min(res, querymn(l, r, s, mid, o << 1));
    if (mid + 1 <= r)
        res = min(res, querymn(l, r, mid + 1, e, o << 1 | 1));
    return res;
}
void work()
{
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build();
    for (int i = 1; i <= n - l + 1; ++i)
    {
        if (i != 1)
            cout << ' ' << querymn(i, i + l - 1);
        else
            cout << querymn(i, i + l - 1);
    }
    cout << '\n';
    for (int i = 1; i <= n - l + 1; ++i)
    {
        if (i != 1)
            cout << ' ' << querymx(i, i + l - 1);
        else
            cout << querymx(i, i + l - 1);
    }
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
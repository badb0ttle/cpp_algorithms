/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 1e5 + 1;
ll t[mx << 2],mul[mx<<2],add[mx<<2], n, q, a[mx],mod;
ll mo(ll x){return (x%mod+mod)%mod;}
void update(ll s, ll e, ll o, ll k,ll x)
{
    t[o]=mo(mo(t[o]*k)+mo(x*(e-s+1)));
    mul[o]=mo(mul[o]*k);
    add[o]=mo(mo(add[o]*k)+x);
}
void pushup(ll idx)
{
    t[idx] = mo(t[idx << 1] + t[idx << 1 | 1]);
}
void pushdown(ll s = 1, ll e = n, ll o = 1)
{
    //  if(mul[o]==1&&add[o]==0)return;
    ll mid = (s + e) >> 1;
    update(s, mid, o << 1, mul[o],add[o]);
    update(mid + 1, e, o << 1 | 1, mul[o],add[o]);
    mul[o]=1,add[o]=0;
}
void build(ll s = 1, ll e = n, ll o = 1)
{
    mul[o]=1;
    if (s == e)
        return t[o] = a[s], void();
    ll mid = (s + e) >> 1;
    build(s, mid, o << 1), build(mid + 1, e, o << 1 | 1);
    pushup(o);
}
void modify(ll l, ll r, ll k,ll x, ll s = 1, ll e = n, ll o = 1)
{
    if (l <= s && r >= e)
        return update(s, e, o, k,x), void();
    pushdown(s, e, o);
    ll mid = (s + e) >> 1;
    if (mid >= l)
        modify(l, r,k, x, s, mid, o << 1);
    if (mid + 1 <= r)
        modify(l, r,k, x, mid + 1, e, o << 1 | 1);
    pushup(o);
}
ll query(ll l, ll r, ll s = 1, ll e = n, ll o = 1)
{
    if (l <= s && r >= e)
    {
        return t[o];
    }
    pushdown(s, e, o);
    ll mid = (s + e) >> 1;
    ll res = 0;
    if (mid >= l)
        res =mo(res+ query(l, r, s, mid, o << 1));
    if (mid + 1 <= r)
        res =mo(res+ query(l, r, mid + 1, e, o << 1 | 1));
    return res;
}
void work()
{
    cin >> n >> q>>mod;
    for (ll i = 1; i <= n; ++i)
        cin >> a[i];
        build();
    while (q--)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            modify(l, r, x,0);
        }
        else if (op == 2)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            modify(l, r, 1,x);
        }
        else if(op==3)
        {
            ll l, r;
            cin >> l >> r;
            cout << query(l, r) << '\n';
        }
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
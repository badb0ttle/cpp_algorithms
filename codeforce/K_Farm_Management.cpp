#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll w, l, r, x;
} a[100007];
vector<ll> Time(100007);
bool cmp(node a, node b)
{
    return a.w > b.w;
}
bool cmp1(node a, node b)
{
    return a.w * a.x > b.w * b.x;
}

void work()
{
    ll n, m;
    cin >> n >> m;
    ll sum_time = 0;

    ll value = 0;
    ll p = 0;
    ll sp = 0, st = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i].w >> a[i].l >> a[i].r;
        st += a[i].r - a[i].l + 1;
        sp += a[i].w * (a[i].r - a[i].l + 1);
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (sum_time + a[i].r <= m)
        {
            sum_time += a[i].r;
            value += a[i].r * a[i].w;
            Time[i] = a[i].r;
            p = i;
        }
        else
        {
            if (sum_time + a[i].l <= m)
            {
                value += (m - sum_time) * a[i].w;
                Time[i] = m - sum_time;
                sum_time += m - sum_time;
                p = i;
            }
            else
            {
                sum_time += a[i].l;
                value += a[i].l * a[i].w;
                Time[i] = a[i].l;
                ll t = a[i].l;

                while (t && p)
                {
                    ll x = Time[p] - a[p].l;
                    // cout<<x<<"*\n";
                    if (x >= t)
                    {
                        sum_time -= t;
                        value -= t * a[p].w;
                        Time[p] -= t;
                        t = 0;
                    }
                    else
                    {
                        sum_time -= x;
                        value -= x * a[p].w;
                        Time[p] = a[p].l;
                        p--;
                        t -= x;
                    }
                }
            }
        }
        a[i].x = Time[i];
    }
    if (p != n)
    {
        sort(a + 1, a + 1 + n, cmp1);
        ll pp = 1;
        ll pw = a[n].w;
        ll pl = a[n].l;
        ll pr = a[n].r;
        // cout << pw;
        ll tim = Time[n];
        sum_time -= tim;
        value -= a[n].w * tim;
        sort(a + 1, a + 1 + n, cmp);
        bool is = 0;
        while (pp != n + 1 && tim)
        {

            if (!is && a[pp].w == pw && pr == a[pp].r && pl == a[pp].l)
            {
                is = 1;
                pp++;
                continue;
            }
            ll x = a[pp].r - Time[pp];
            if (x < tim)
            {
                sum_time += x;
                value += x * a[pp].w;
                Time[pp] = a[pp].l;
                pp++;
                tim -= x;
            }
            else
            {
                sum_time += tim;
                value += tim * a[pp].w;
                Time[pp] += tim;
                tim = 0;
            }
        }
    }
    cout << value;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--)
        work();
    return 0;
}
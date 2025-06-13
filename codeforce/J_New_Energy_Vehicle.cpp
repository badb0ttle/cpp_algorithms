/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#
const int mx=1e5+5;
struct cdz
{
    int kep, nx, idx;
    bool operator<(const cdz &b) const
    {
        return nx > b.nx;
    }
};
priority_queue<cdz> hv, bnk;
int a[mx],n,m;
pair<int, int> p[mx];
queue<int> charge[mx];
void work()
{
    cin >> n >> m;
    while (!hv.empty())hv.pop();
    while (!bnk.empty())bnk.pop();
    for (int i = 0; i <= n; ++i)while (!charge[i].empty())charge[i].pop();
    for (int i = 1; i <= n; ++i)cin >> a[i];
    for (int i = 1; i <= m; ++i)
    {
        cin >> p[i].first >> p[i].second;
        charge[p[i].second].push(i);
    }
    p[m + 1] = {LLONG_MAX, 0};
    charge[0].push(m + 1);
    for (int i = 1; i <= n; ++i)charge[i].push(m + 1);
    for (int i = 1; i <= n; ++i)hv.push({a[i], charge[i].front(), i});
    ll ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        while (!hv.empty() && ans < p[i].first)
        {
            cdz t = hv.top();
            hv.pop();
            if (t.kep + ans > p[i].first)
            {
                t.kep -= p[i].first - ans;
                ans = p[i].first;
                hv.push(t);
            }
            else
            {
                ans += t.kep;
                t.kep = 0;
                bnk.push(t);
            }
        }
        if (hv.empty() && ans < p[i].first)
        {
            cout << ans << '\n';
            return;
        }
        if (!hv.empty() && hv.top().nx == i)
        {
            cdz t = hv.top();
            hv.pop();
            charge[t.idx].pop();
            t.nx = charge[t.idx].front();
            t.kep = a[t.idx];
            hv.push(t);
        }
        else if (!bnk.empty() && bnk.top().nx == i)
        {
            cdz t = bnk.top();
            bnk.pop();
            charge[t.idx].pop();
            t.nx = charge[t.idx].front();
            t.kep = a[t.idx];
            hv.push(t);
        }
    }
    while (!hv.empty())
    {
        ans += hv.top().kep;
        hv.pop();
    }
    cout << ans << '\n';
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}
/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 2e5 + 1;
ll a[mx], cnt[31];
void work()
{
    ll n;
    cin >> n;
    memset(cnt,0,sizeof cnt);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (ll j = 0; j < 30; j++)
        {
            cnt[j] += ((a[i] >> j) & 1);
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (ll j = 0; j < 30; j++)
        {
            if (((a[i] >> j) & 1))
                sum += (1 << j) * (n - cnt[j]);
            else
                sum += (1 << j) * cnt[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
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
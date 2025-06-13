/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define pair <int, int> PII
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 1e5 + 1;
ll n, k;
ll a[mx];
void work()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll l = 0, r = *max_element(a, a + n), ans = 0;
    while (l + 1 != r)
    {
        ll mid = l + r >> 1;
        ll sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] > mid)
                sum += a[i] - mid;
        }
        if (sum >= k)
        {
            ans = mid;
            l = mid;
        }
        else
            r = mid;
    }
    cout << ans;
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
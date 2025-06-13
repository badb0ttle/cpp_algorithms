/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
vector<ll> pre(const vector<ll> a)
{
    int n = a.size();
    vector<ll> Pre(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        Pre[i] = Pre[i - 1] + a[i - 1];
    }
    return Pre;
}

void work()
{
    int m1, m2;
    cin >> m1 >> m2;

    vector<ll> a(m1), b(m2);
    for (int i = 0; i < m1; ++i)
        cin >> a[i];
    for (int i = 0; i < m2; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    vector<ll> pa = pre(a);
    ll suma = pa[m1];

    sort(b.begin(), b.end(), greater<ll>());
    vector<ll> pb = pre(b);
    ll sumb = pb[m2];

    if (suma > sumb)
    {
        cout << "0\n";
        return;
    }

    int ans = -1;
    int mx = min(m1, m2);

    for (int k = 0; k <= mx; ++k)
    {
        ll suma_r = suma - pa[k];
        ll sumb_r = sumb - pb[k];
        if (suma_r > sumb_r)
        {
            ans = k;
            break;
        }
    }

    if (m2 <= m1)
    {
        int tmp = m2;
        if (tmp <= m1)
        {
            ll suma_r = suma - pa[tmp];
            if (suma_r > 0)
            {
                if (ans == -1 || tmp < ans)
                {
                    ans = tmp;
                }
            }
        }
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
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ld wc = 1e-8;
void solve()
{
    int m;
    cin >> m;
    ll ans = 0;
    while (m--)
    {
        ld a, b;
        cin >> a >> b;
        ld x = a * b;
        if (x < 0)
            x = 0;
        ll z = floor(x);
        ld dif = x - z;
        if (0.25 - dif > wc)
        {
            ans += z * 2;
        }
        else if (dif >= 0.75 - wc)
        {
            ans += (z + 1) * 2;
        }
        else
        {
            ans += z * 2 + 1;
        }
    }
    if (ans % 2 == 0)
    {
        cout << (ans>>1) << '\n';
    }
    else
    {
        cout << (ans>>1) << ".5\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
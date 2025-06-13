/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 长路漫漫 OI 苦，不开 ll 也得补
#define sc scanf
#define pr printf
ll sm(ll a, ll b, ll mod) // slow mul
{
    a %= mod;
    ll res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return res;
}
void work()
{
    ll a, b, c, d;
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
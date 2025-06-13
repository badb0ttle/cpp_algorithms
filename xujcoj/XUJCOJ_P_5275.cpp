/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
ll dp[13];
// 查了一下发现容斥原理有这个...
// https://zh.wikipedia.org/wiki/%E6%8E%92%E5%AE%B9%E5%8E%9F%E7%90%86?utm_source=chatgpt.com#%E9%94%99%E6%8E%92
ll derangement(int n)
{ // derangement "错乱"
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;

    ll a = 1, b = 0, c;
    for (int i = 2; i <= n; i++)
    {
        c = (i - 1) * (b + a);
        a = b;
        b = c;
    }
    return c;
}

void work()
{
    int n = 12;
    cout << derangement(n) << '\n';
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
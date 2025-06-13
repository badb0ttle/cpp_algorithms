/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 1e6 + 1;
int n;
int a[mx], s[4];
void work()
{
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        s[a[i]]++;
    }
    int ans = INT_MAX;
    for (int i = 0; i <= 3; ++i)
    {
        int tmp = (s[(i + 1) % 4]) + 2 * (s[(i + 2) % 4]) + 3 * (s[(i + 3) % 4]);
        int t1 = (4 - (tmp + i) % 4) % 4;
        ans = std::min(ans, tmp + t1);
    }
    std::cout << ans << '\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    // std::cin>>_;
    while (_--)
        work();
    return 0;
}
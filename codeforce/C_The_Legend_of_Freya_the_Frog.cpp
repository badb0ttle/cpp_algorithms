/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
int x, y, k;
void work()
{
    std::cin >> x >> y >> k;
    int dx = x / k, dy = y / k;
    if (y >= x)
    {
        if (y % k != 0)
            dy++;
        std::cout << 1LL * dy * 2 << '\n';
        return;
    }
    else if (y < x)
    {
        if (x % k != 0)
            dx++;
        std::cout << 1LL * dx * 2 - 1 << '\n';
        return;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    while (_--)
        work();
    return 0;
}
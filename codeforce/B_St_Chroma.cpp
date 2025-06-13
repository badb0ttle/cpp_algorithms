/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
int n, x;
void work()
{
    std::cin >> n >> x;
    std::vector<int> p;
    if (x == 0) {
        p.push_back(1);
        p.push_back(0);
        for (int i = 2; i < n; ++i)
            p.push_back(i);
    } else {
        for (int i = 0; i < x; ++i)
            p.push_back(i);
        for (int i = x+1; i < n; ++i)
            p.push_back(i);
        p.push_back(x);
    }

    for (auto v : p)
        std::cout << v << ' ';
    std::cout << '\n';
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
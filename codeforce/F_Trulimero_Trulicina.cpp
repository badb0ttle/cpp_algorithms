/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
i64 n, m, k;
void work()
{
    std::cin >> n >> m >> k;
    int tmp = 1, t = 0;
    if (m % k != 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (j != m)
                    std::cout << tmp + (t % k) << ' ';
                else
                    std::cout << tmp + (t % k);
                t++;
            }
            std::cout << '\n';
        }
    }
    else
    {
        int tmp = 1, t = 0, d = m / k;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= d; ++j)
            {
                if (i % 2 != 0)
                {
                    for (int x = 1; x <= k; ++x)
                    {
                        if (j == d && x == k)
                            std::cout << x;
                        else
                            std::cout << x << ' ';
                    }
                }
                else
                {
                    for(int x=2;x<=k+1;++x)
                    {
                        if (j == d && x == k+1)
                            std::cout << 1;
                        else
                            std::cout << (x%(k+1)==0?1:x) << ' ';
                    }
                }
            }
            std::cout<<'\n';
        }
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
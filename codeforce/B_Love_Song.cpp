/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 1e5 + 1;
int n, q, l, r;
std::string s;
int pre[mx];
void work()
{
    std::cin >> n >> q;
    std::cin >> s;
    for (int i = 0; i < n; ++i)
    {
        pre[i + 1] = pre[i] + (s[i] - 'a' + 1);
    }
    while (q--)
    {
        std::cin >> l >> r;
        std::cout << pre[r] - pre[l - 1] << '\n';
    }
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
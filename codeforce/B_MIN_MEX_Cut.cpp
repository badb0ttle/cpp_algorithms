/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
void work()
{
    std::string s;
    std::cin >> s;
    int n = s.size();
    int ans = 0;
    bool has0 = 0, has1 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
            has0 = 1;
        else
            has1 = 1;
        if (has0 && has1)
        {
            ans += 2;
            has0 = has1 = 0;
        }
    }
    if (has0)
        ans += 1;
    if (has1)
        ans += 0;
    std::cout << ans << '\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    std::cin>>_;
    while (_--)
        work();
    return 0;
}
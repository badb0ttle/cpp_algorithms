/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
void work()
{
    std::string s;
    std::cin >> s;
    std::string ans = "" + s[0];
    char t = s[0];
    int tmp = 0, op = -1;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == '+')
        {
            if (i != 2)
            {
                if (t + op * tmp >= 'Z')
                    t = 'Z';
                else if (t + op * tmp <= 'A')
                    t = 'A';
                else
                    t = t + op * tmp;
                ans = ans + t;
            }
            tmp = 0;
            op = 1;
        }
        else if (s[i] == '-')
        {
            if (i != 2)
            {
                if (t + op * tmp >= 'Z')
                    t = 'Z';
                else if (t + op * tmp <= 'A')
                    t = 'A';
                else
                    t = t + op * tmp;
                ans = ans + t;
            }
            tmp = 0;
            op = -1;
        }
        else
        {
            tmp = tmp * 10 + s[i] - '0';
        }
    }
    if (t + op * tmp >= 'Z')
        t = 'Z';
    else if (t + op * tmp <= 'A')
        t = 'A';
    else
        t = t + op * tmp;
    ans = ans + t;
    std::cout << ans << '\n';
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
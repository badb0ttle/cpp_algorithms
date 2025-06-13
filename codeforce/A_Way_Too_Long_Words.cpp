/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
void work()
{
    string s;
    cin >> s;
    int l = s.size();
    if (l > 10)
        cout << s[0] << s.size() - 2 << s[l - 1] << '\n';
    else
        cout << s << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}
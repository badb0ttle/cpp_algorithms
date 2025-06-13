/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
void work()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    bool tr = 0;
    while (m--)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            int k;
            cin >> k;
            k--;
            if (tr)
                k = n - 1 - k;
            cout << a[k] << '\n';
        }
        else if (num == 2)
        {
            int k, x;
            cin >> k >> x;
            k--;
            if (tr)
                k = n - 1 - k;
            a[k] = x;
        }
        else if (num == 3)
        {
            tr ^=1;
        }
    }
}
signed main()
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
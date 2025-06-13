/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
void work()
{
    int n, m, h;
    cin >> n >> m >> h;
    int mid = m + n - 1;
    for (int i = 0; i < n; ++i)
    {
        int tmp = m + i;
        for (int j = 1; j <= tmp; ++j)
        {
            for (int k = 1; k <= mid - j; ++k)
            {
                cout << " ";
            }
            for (int k = 1; k <= j * 2 - 1; ++k)
            {
                cout << "*";
            }
            cout << '\n';
        }
    }
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < mid - 1; ++j)
        {
            cout << " ";
        }
        cout << "*" << '\n';
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
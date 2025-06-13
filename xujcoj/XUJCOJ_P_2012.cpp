/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
// 我好像是有什么大饼
int cnt[101], tmp;
void work()
{
    memset(cnt, 0, sizeof(cnt));
    int m, a;
    cin >> m >> a;
    for (int i = 0; i < m; ++i)
    {

        cin >> tmp;
        cnt[tmp]++;
    }
    if (m < 2)
    {
        cout << "No\n";
        return;
    }
    int mx1 = -1, mx2 = -1;
    for (int i = 100; i >= 0; --i)
    {
        if (cnt[i] > 0)
        {
            if (mx1 == -1)
            {
                mx1 = i;
            }
            else if (mx2 == -1)
            {
                mx2 = i;
                break;
            }
        }
    }
    if (cnt[mx1] >= 2)
        cout << "No\n";
    else
        cout << (mx2 == a ? "Yes\n" : "No\n");
}
int main()
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
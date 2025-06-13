/*blank*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mx = 2e5 + 1;
int n, m;
struct cir
{
    int x, r;
} ci[mx];
void work()
{
    cin >> n >> m;
    unordered_map<i64, i64> mp;
    for (int i = 1; i <= n; ++i)
        cin >> ci[i].x;
    for (int i = 1; i <= n; ++i)
        cin >> ci[i].r;

    for (int i = 1; i <= n; ++i)
    {
        int xi = ci[i].x, ri = ci[i].r;
        for(i64 j=xi-ri,k=xi+ri;;++j,--k)
        {
            if(j>k)break;
            i64 dy= (i64)sqrt(1LL*ri * ri - 1LL*(j - xi) * (j - xi));
            mp[j]=max(mp[j],dy);
            mp[k]=max(mp[k],dy);
        }
    }
    i64 sum = 0;
    for (auto [x, dy] : mp)
        sum += dy * 2 + 1;
    cout << sum << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}
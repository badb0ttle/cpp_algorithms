/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 1e3 + 1;
int n, m, c;
int pre[mx][mx], a[mx][mx];
void work()
{
    std::cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            pre[i][j] = -1*pre[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] + a[i][j];
        }
    }
    int ans=INT_MIN,ax,ay;
    for (int i = 1; i <= n - c + 1; ++i)
    {
        for (int j = 1; j <= m - c + 1; ++j)
        {
            int tmp=-1*pre[i-1][j+c-1]-pre[i+c-1][j-1]+pre[i-1][j-1]+pre[i+c-1][j+c-1];
            if(ans<tmp)
            {
                ans=tmp;
                ax=i,ay=j;
            }
        }
    }
    std::cout<<ax<<' '<<ay<<'\n';
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
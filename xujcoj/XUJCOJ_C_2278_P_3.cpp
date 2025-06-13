/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 21;
int n, a[mx];
void work()
{
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    int sum = std::accumulate(a + 1, a + 1 + n, 0);
    std::vector<int>vec;
    for (int i = 1, j = n; i <= n; ++i, --j)vec.push_back(std::max(a[i],a[j]));
    int ans=0;
    for(int i=0;i<n;i+=2)ans+=vec[i];
    std::cout<<(ans>sum-ans?"true":"false");
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
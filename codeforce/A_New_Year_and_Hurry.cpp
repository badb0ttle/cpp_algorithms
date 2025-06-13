/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
int n, k;
void work()
{
    std::cin >> n >> k;
    int t = 240 - k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)  a[i] = 5 * i;
    for(int i=1;i<=n;++i)a[i]+=a[i-1];
    int l = 0, r = n;
    while (l + 1 != r)
    {
        int mid=(l+r)>>1;
        if(a[mid]>=t)r=mid;
        else l=mid;
    }
    if(a[r]>t)r--;
    std::cout<<r<<'\n';
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
/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 2e5 + 1;
int n, a[mx];
i64 sum;
bool check(int x)
{

}
bool isq(i64 x)
{
    i64 l=0,r=sum;
    while(l+1!=r)
    {
        i64 mid=(1LL*(l+r))>>1;
        if(check(mid))
    }
}
void work()
{
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    sum = std::accumulate(a + 1, a + 1 + n, 0LL);
    std::cout<<(isq(sum)?"YES\n":"NO\n");
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
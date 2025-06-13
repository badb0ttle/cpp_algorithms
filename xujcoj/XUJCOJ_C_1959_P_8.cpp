/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=5051;
int a[mx][1001];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            std::cin>>a[i][j];
        }
    }
    for(int i=n-1;i>=1;--i)
    {
        for(int j=1;j<=i;++j)
        {
            a[i][j]+=std::max(a[i+1][j],a[i+1][j+1]);
        }
    }
    std::cout<<a[1][1]<<'\n';
    return 0;
}
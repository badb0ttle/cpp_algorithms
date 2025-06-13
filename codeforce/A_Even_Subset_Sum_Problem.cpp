/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 101;
int n, a[mx];
void work()
{
    std::cin >> n;
    int i1 = -1, i2 = -1,o=-1;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        if (!(a[i] & 1))
        {
           o=i;
        }
        if (i1 != -1)
        {
            i2=i;
        }
        else
        {
            i1 = i;
        }
    }
    if (n == 1&&o==-1)
    {
        std::cout << "-1\n";
    }
    else if(o!=-1)
    {
        std::cout<<"1\n"<<o<<'\n';
    }
    else
    {
        std::cout<<"2\n"<<i1<<' '<<i2<<'\n';
    }
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
/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
int a,b,c,d;
void work()
{
    std::cin>>a>>b>>c>>d;
    if(a==b&&a==c&&a==d)std::cout<<"Yes\n";
    else std::cout<<"No\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _;
    std::cin>>_;
    while(_--)work();

    return 0;
}
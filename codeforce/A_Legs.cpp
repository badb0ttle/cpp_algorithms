/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
int n;
void work()
{
   std::cin>>n;
   int t=n/4;
   int t2=n%4;
   std::cout<<t+(t2==0?0:1)<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
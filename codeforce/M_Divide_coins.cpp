/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
void work()
{
   int n,m;
   std::cin>>n>>m;
   for(int i=1;i<=m;++i)
   {
    std::cout<<"1";
   }
   for(int i=m+1;i<=n;++i)
   {
    std::cout<<"4";
   }
   std::cout<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    //std::cin>>_;
    while(_--)work();
    return 0;
}
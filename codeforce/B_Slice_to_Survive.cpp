/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
int n,m,a,b;
int gn(int x) {
    return (x == 1 ? 0 : (int)ceil(log2(x)));
}
void work()
{
   std::cin>>n>>m>>a>>b;
   std::cout<<1+std::min(gn(std::min(a,n-a+1))+gn(m),gn(std::min(b,m-b+1))+gn(n))<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
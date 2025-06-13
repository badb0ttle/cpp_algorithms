/*blank*/
#include <bits/stdc++.h>
using i64 = long long;
int n,m,p,q;
//
void work()
{
    std::cin>>n>>m>>p>>q;
    //q  p&1  p/2,p+1/2 p/2*a+(p+1)/2*b
    //q  !p&1 p/2,p/2  p/2*(a+b)
    if(!(p&1))
    {
        if(m*2%p)
        {
            std::cout<<"NO\n";
            return ;
        }
        std::cout<<"YES\n";
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _;
    std::cin>>_;
    while(_--)work();

    return 0;
}
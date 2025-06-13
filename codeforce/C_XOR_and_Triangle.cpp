/*blank*/
#include <bits/stdc++.h>
int x,y,t;
using i64 = long long;
int getlen(int x)
{
    int c=0;
    while(x)
    {
        c++;
        x>>=1;
    }
    return c;
}
void work()
{
    std::cin>>x;
    int len=getlen(x)-1;
    long long  mx=pow(2,len)-1;
    // std::cout<<mx<<'\n';
    long long xo=mx^x;
    if(x+xo<=mx||abs(x-xo)>=mx)
    {
        std::cout<<"-1\n";
    }
    else
    std::cout<<mx<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _;
    std::cin>>_;
    while(_--)work();
    return 0;
}
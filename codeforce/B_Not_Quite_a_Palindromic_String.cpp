/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
unsigned int n,k;
i64 num;
std::string s;
i64 tr2to10(std::string s)
{
    i64 x=0;
    int tmp=1;
    std::reverse(s.begin(),end(s));
    for(char i:s)
    {
        x+=(i-'0')*tmp;
        tmp<<=1;
    }
    return x;
}
void work()
{
    std::cin>>n>>k>>s;
    num=tr2to10(s);
    int n1=__builtin_popcount(num);
    int n0=n-n1;
    // int n0=0,n1=0;
    // for(const auto&i:s)
    // {
    //     if(i=='0')n0++;
    // }
    // n1=n-n0;
    int mn =std:: max(n0, n1) - n / 2;
    int mx = n0 / 2 + n1 / 2;
    if(k >= mn && (k - mn) % 2 == 0 && k <= mx) std::cout << "YES\n";
    else std::cout << "NO\n";

}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
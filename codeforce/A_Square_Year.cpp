/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
std::string s;
bool ispf(int num)
{
    return (int) sqrt(num) * (int) sqrt(num) == num;
}
void work()
{
    std::cin>>s;
    int num=std::stoi(s);
    if(num==0)
    {
        std::cout<<"0 0\n";
        return;
    }
    if(ispf(num))
    {
        std::cout<<sqrt(num)-1<<' '<<1<<'\n';
    }
    else std::cout<<"-1\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
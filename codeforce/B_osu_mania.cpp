/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=501;
int n;
char mp[mx][5];
void work()
{
    std::cin>>n;
    std::vector<int>vec;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=4;++j)
        {
            std::cin>>mp[i][j];
            if(mp[i][j]=='#')vec.push_back(j);
        }
    }
    reverse(vec.begin(),vec.end());
    bool f=0;
    for(int i:vec)
    {
        if(!f)
        {
            f=1;
            std::cout<<i;
        }
        else std::cout<<' '<<i;
    }
    std::cout<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
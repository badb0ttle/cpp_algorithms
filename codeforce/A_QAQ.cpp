/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
std::string s;
const int mx=101;
int preq[mx],sufq[mx];
void work()
{
   std::cin>>s;
   int len=s.size();
    for(int i=0;i<len;++i)preq[i + 1] = preq[i] + (s[i] == 'Q');
    for(int i=len-1;i>=0;--i)sufq[i] = sufq[i+1] + (s[i] == 'Q');
    i64 res=0;
    for(int i=0;i<len;++i)
    {
        if(s[i]=='A')res+=preq[i]*sufq[i];
    }
    std::cout<<res<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    //std::cin>>_;
    while(_--)work();
    return 0;
}
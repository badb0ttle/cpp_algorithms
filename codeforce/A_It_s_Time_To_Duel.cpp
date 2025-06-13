/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=101;
int n;
int a[mx],s[2];
void work()
{
    std::memset(s,0,sizeof(s));
   std::cin>>n;
   for(int i=1;i<=n;++i){std::cin>>a[i];s[a[i]]++;}
   if(s[1]==0||s[0]==0)
   {
    std::cout<<"YES\n";return;
   }
   for(int i=1;i<=n-1;++i)
   {
    if(a[i]==0&&a[i+1]==0)
    {
        std::cout<<"YES\n";
        return;
    }
   }
   std::cout<<"NO\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=201;
int n,a[mx];
void work()
{
   std::cin>>n;
   for(int i=1;i<=n;++i)std::cin>>a[i];
   bool f=0;
   for(int i=1;i<=n-1;++i)
   {
        f=0;
        int x=a[i],y=a[i+1];
        if(x>y)std::swap(x,y);

        if(x+x<=y||y-x>=x)
        {
            f=1;
        }
        std:: swap(x,y);
        if(x+x<=y||y-x>=x)
        {
            f=1;
        } if(!f){std::cout<<"YES\n";return;}

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
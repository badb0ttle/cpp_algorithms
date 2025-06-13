/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
int a,b,c;
void work()
{
   std::cin>>a>>b>>c;
   if((a+b+c)%3!=0)
   {
    std::cout<<"NO\n";
    return ;
   }
   int avg=(a+b+c)/3;
   if(a>avg||b>avg)
   {
    std::cout<<"NO\n";
    return;
   }
   std::cout<<"YES\n";
   
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
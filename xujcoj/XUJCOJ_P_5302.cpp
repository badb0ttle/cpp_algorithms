/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=1001;
int m,a;
int c[11],d[11],dp[mx];
const int inf=0x3f3f3f;
void work()
{
   std::fill(dp, dp + mx, inf);
   dp[0]=0; 
   std::cin>>m>>a;
   for(int i=1;i<=a;++i)std::cin>>c[i];
   for(int i=1;i<=a;++i)std::cin>>d[i];
   for(int i=1;i<=a;++i)
   {
    std::vector<int>vec;
    int x=1,s=d[i];
    while(s>=x)
    {
        vec.push_back(x);
        s-=x;
        x<<=1;
    }
    if(s)vec.push_back(s);
    for(int k:vec)
    {
        for(int j=m;j>=k*c[i];--j)dp[j]=std::min(dp[j],dp[j-k*c[i]]+k);
    }
   }
   if(dp[m]==inf)std::cout<<"-1\n";
   else
   std::cout<<dp[m]<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx=2e5+1;
int n,k;
double r0,c0,p,L,R,v;
double r[mx],c[mx];
void work()
{
    memset(r,0,sizeof(r));
   std::cin>>n>>k;
   std::cin>>r0>>c0>>p>>L>>R;
   r[0]=r0;
   c[0]=c0;
   
   for(int i=1;i<=k;++i)
   {
        int idx;
        std::cin>>idx;
        std::cin>>r[idx];
   }
   for(int i=1;i<=n;++i)
   {
        if(!r[i])r[i]=L;
   }
   double sl=std::accumulate(r+1,r+1+n,0.0);
   for(int i=1;i<=n;++i)
   {
    c[i]=p*c[i-1]+(1-p)*r[i-1];
   }
   double sr=std::accumulate(c+1,c+1+n,0.0);
   std::printf("%.10f\n",sr-sl);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}
/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
int n;
void work()
{
   std::cin>>n;
   int cnt=0;
   std::vector<int>vec;
   int base=1;
   while(n)
   {
    int tmp=n%10;
    if(tmp!=0)
    {vec.push_back(tmp*base);cnt++;}
    n/=10;
    base*=10;
    
   }
   std::cout<<cnt<<'\n';
   bool f=0;
   for(int i:vec)
   {
    if(!f)
    {
        f=1;
        std::cout<<i;
    }
    else std::cout<<" "<<i;
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
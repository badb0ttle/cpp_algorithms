/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
void work()
{
    int n;
    std::cin>>n;
    std::vector<int>a(n);
    for(int&i:a)std::cin>>i;
    sort(begin(a),end(a));
    for(int i=0;i<n-1;++i)
    {
        a[i+1]=a[i]+a[i+1]-1;
    }
   std:: cout<<a[n-1]<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _;
    std::cin>>_;
    while(_--)work();

    return 0;
}
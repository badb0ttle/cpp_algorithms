/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
const int mx = 1e6 + 1;
int n;
void work()
{
    std::cin >> n;
    int a[n];
    for(int&i:a)std::cin>>i;
    int cd=a[0];
    int cnt = 1;
    for (int i = 1; i <n; ++i)
    {
        if(!cnt)
        {
            cd=a[i];
            cnt=1;
        }
        else if(a[i]==cd)cnt++;
        else cnt--;
    }
    cnt=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==cd)cnt++;
    }
    if(cnt>n/2)std::cout<<cd<<' '<<cnt<<'\n';
    else std::cout<<"None\n";

}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    while (_--)
        work();
    return 0;
}
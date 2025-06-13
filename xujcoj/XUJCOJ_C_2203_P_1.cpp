/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
ll n, c;
void work()
{
    cin>>n;
    for (int i = 5; i <= n; i++)
    {
        if (i % 5 == 0)
        {
            c++;
        }
        if (i % 25 == 0)
        {
            c++;
        }
    }
    cout<<c<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}
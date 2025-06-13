/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
int n;
const int mx = 1001;
int dp[mx][mx];
void work()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> dp[i][j];
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
        }
    }
    cout<<*max_element(begin(dp[n]),end(dp[n]))<<'\n';
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
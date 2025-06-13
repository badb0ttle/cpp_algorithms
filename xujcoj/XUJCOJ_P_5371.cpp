/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
int vis[10];
ll ans;
ll dp[31][10][4];
void work()
{
    ll ans = -3; 
    for (int j = 0; j < 10; j++)
    {
       dp[1][j][1] = 1;
       ans += dp[1][j][1];
    }
    for (int i = 2; i <= 30; i++)
    {
       for (int j = 0; j < 10; j++)
       {
           for (int k = 0; k < j; k++)
           {
               dp[i][j][1] += dp[i - 1][k][1];
               dp[i][j][1] += dp[i - 1][k][2];
               dp[i][j][1] += dp[i - 1][k][3];
           }
           dp[i][j][2] = dp[i - 1][j][1];
           dp[i][j][3] = dp[i - 1][j][2];
           ans = ans + dp[i][j][1] + dp[i][j][2] + dp[i][j][3];
       }
    }
    cout << ans << '\n';
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
//cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}
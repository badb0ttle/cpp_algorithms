/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define pair<int,int> PII
#define debug(x) cout<<#x<<'='<<x<<'\n'
int x,y;
int dp[11][11];
/*你手上有x颗糖果，要放在y个盘子里，允许有些盘子为空，请问共有多少种不同的分法？注意2、1和1、2是同一种分法。*/
void work()
{
    cin>>x>>y;
    for(int i=0;i<=x;++i){dp[i][0]=0;dp[i][1]=1;dp[0][i]=1;}
    for(int i=1;i<=x;++i)
    {
        for(int j=1;j<=y;++j)
        {
            if(i>=j) dp[i][j]=dp[i-j][j]+dp[i][j-1];
            else dp[i][j]=dp[i][j-1];
        }
    }
    cout<<dp[x][y];
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
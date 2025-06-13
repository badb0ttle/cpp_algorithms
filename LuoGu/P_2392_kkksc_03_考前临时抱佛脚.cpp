/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx=21;
int a[5][mx],s[5],sum[5],dp[10086];
void work()
{
    for(int i=1;i<=4;++i)cin>>s[i];
    for(int i=1;i<=4;++i)for(int j=1;j<=s[i];++j){cin>>a[i][j];sum[i]+=a[i][j];}
    int ans=0;
    for(int i=1;i<=4;++i)
    {
        for(int j=1;j<=s[i];++j)
        {
            for(int k=sum[i]/2;k>=a[i][j];--k)
            {
                dp[k]=max(dp[k],dp[k-a[i][j]]+a[i][j]);
            }
        }
        ans+=max(dp[sum[i]/2],sum[i]-dp[sum[i]/2]);
        for(int j=0;j<=sum[i]/2;++j)dp[j]=0;
    }
    cout<<ans<<'\n';
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
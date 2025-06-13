/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx=101;
const int N=1001;
int n,m;
int a[mx],dp[N],t[mx];
void work()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i]>>t[i];
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=n;j>=a[i];--j)
        {
            if(j-a[i]>=0)dp[j]=max(dp[j],dp[j-a[i]]+t[i]);
            else dp[j]=dp[j];
        }
    }
    cout<<dp[n]<<'\n';
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
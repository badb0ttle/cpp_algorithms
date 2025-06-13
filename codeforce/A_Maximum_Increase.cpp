/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=1e5+1;
int a[mx],n;

void work()
{
    cin>>n;
    int dp[n+1];
    fill(dp+1,dp+1+n,1);
    for(int i=1;i<=n;++i)cin>>a[i];
    dp[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(a[i]>a[i-1])dp[i]=dp[i-1]+1;
        else dp[i]=1;
    }
    cout<<*max_element(dp+1,dp+1+n)<<'\n';
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
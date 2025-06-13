/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=1e6+1;
int n,a[mx];
void work()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    ll sum=accumulate(a+1,a+n+1,0LL);
    cout<<max(sum,(ll)(*max_element(a+1,a+n+1))*2)<<'\n';
    
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
// cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}
/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
ll n;
ll a[]={1,5,10,20,100};
void work()
{
    cin>>n;
    int ans=0;
    for(int i=4;i>=0;i--)
    {
        ans+=n/a[i];
        n-=n/a[i]*a[i];
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
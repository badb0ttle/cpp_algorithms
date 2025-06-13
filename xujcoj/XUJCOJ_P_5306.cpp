/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf

void work()
{
    ll a,b;
    cin>>a>>b;
    a--;
    ll a2=a/2,b2=b/2,a3=a/3,b3=b/3,a5=a/5,b5=b/5;
    ll a23=a/6,b23=b/6,a25=a/10,b25=b/10,a35=a/15,b35=b/15;
    ll a235=a/30,b235=b/30;
    cout<<b2+b3+b5-2*b23-2*b25-2*b35+3*b235-(a2+a3+a5-2*a23-2*a25-2*a35+3*a235)<<'\n';
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}
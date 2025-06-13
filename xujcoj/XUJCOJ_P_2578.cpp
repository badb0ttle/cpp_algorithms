/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
struct f
{
    ll a,b,pre;
};
bool cmp(f a,f b)
{
    return a.a<b.a;
}
int n;
void work()
{
    cin>>n;
    f s[n];
    for(auto&i:s)cin>>i.a;
    for(auto&i:s)cin>>i.b;
    sort(s,s+n,cmp);
    s[0].pre=s[0].a*s[0].b;
    for(int i=1;i<n;++i)
    {
        s[i].pre=s[i-1].pre+s[i].a*s[i].b;
        s[i].b+=s[i-1].b;
    }
    ll ans=LLONG_MAX;
    for(int i=0;i<n;++i)
    {
        ll tmp=s[i].a * s[i].b - s[i].pre + (s[n-1].pre - s[i].pre) - s[i].a * (s[n-1].b - s[i].b);
        ans=min(tmp,ans);
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
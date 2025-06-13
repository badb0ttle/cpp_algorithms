/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx=22;
int m,n;
int dp[mx];
string s;
int a,b,c;
struct p
{
    int a,b,c;
};
void work()
{
    map<string,p>mp;
    cin>>m>>n;
    m=21-m;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b>>c>>s;
        mp[s].a+=a;
        mp[s].b=b;
        mp[s].c=c;
    }
    int sz=mp.size(),x=0;
    for(auto i:mp)
    {
            
    }
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
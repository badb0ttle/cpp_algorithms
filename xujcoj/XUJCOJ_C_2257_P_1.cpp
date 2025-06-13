/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
ll qp(ll a, ll b, ll mod)//quick power
{
a%=mod;
   ll res = 1;
    while (b)
    {
        if (b & 1)res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
ll a,b,c;
void work()
{
    cin>>a>>b>>c;
    if(b==0)
    {
        if(c==1)cout<<"0\n";
        else cout<<"1\n";
    }
    else
    {
        cout<<qp(a,b,c)<<'\n';
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
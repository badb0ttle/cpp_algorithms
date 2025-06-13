/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=45;
ll r,fac[mx];
void pre()
{
    fac[1]=1;
    for(int i=2;i<mx;i++)
    {
        fac[i]=fac[i-1]*i%10000000000;
    }
}
void work()
{
    int a;
    cin>>a;
    if(a>=45)cout<<"0\n";
    else cout<<fac[a]<<'\n';
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
cin >> _;
pre();
//sc("%d",&_);
while (_--)work();
return 0;
}
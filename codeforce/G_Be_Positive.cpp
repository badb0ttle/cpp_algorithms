/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
void work()
{
    ll n;
    cin>>n;
    if(n%4==0||n==1){cout<<"impossible\n";return;}
    cout<<"1 0";
    for(ll i=2;i<=n-1;++i)
    {
        if(i%4==3)
        {
            cout<<' '<<i+1<<' '<<i;
            i++;
        }
        else
        {
            cout<<' '<<i;
        }
    }
    cout<<'\n';
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
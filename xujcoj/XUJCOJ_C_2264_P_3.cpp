/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
int m,a,b,c,d;
void work()
{
    cin>>m>>a>>b>>c>>d;
    int t=a;
    int x=c-b;
    for(int i=1;i<=d;++i)
    {
        t+=x;
        t=min(m,t);
        t=max(t,0);
    }
    cout<<t<<'\n';
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
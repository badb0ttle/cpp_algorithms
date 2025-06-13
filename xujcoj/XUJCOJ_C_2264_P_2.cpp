/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define ull unsigned long long
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
int a,b,c,d,e,f,x;
ull sum;
void work()
{
    cin>>a>>b>>c>>d>>e>>f;
    vector<int>t(e);
    t[0]=a;
    for(int i=1;i<e;++i)
    {
        t[i]=(1LL*t[i-1]*b+c)%d;
    }
    sort(t.begin(),t.end());
    for(int i=1;i<=f;++i)
    {
        cin>>x;
        if(binary_search(t.begin(),t.end(),x))
        {
            sum+=x;
        }
    }
    cout<<sum;
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
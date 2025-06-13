/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx=5e6+1;
int n,p,x,y,z;
int dif[mx],a[mx];
void work()
{
    cin>>n>>p;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;i++)
	{
		dif[i]=a[i]-a[i-1];
	}
    for(int i=1;i<=p;++i)
    {
        cin>>x>>y>>z;  
        dif[x]+=z;
        dif[y+1]-=z;
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;++i)
    {
        a[i]=a[i-1]+dif[i];
        if(a[i]<ans)ans=a[i];
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
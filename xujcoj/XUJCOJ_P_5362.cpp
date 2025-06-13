/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=11;
int x[mx],a,b;
bool vis[mx];
set<int>ans;
vector<int>tmp;
void dfs(int dep)
{
    if(dep>=b)
    {
        int ans1=accumulate(begin(tmp),end(tmp),0);
        ans.insert(ans1);
    }
    for(int i=1;i<=a;++i)
    {
        if(!vis[i])
        {
            vis[i]=1;
            tmp.push_back(x[i]);
            dfs(dep+1);
            vis[i]=0;
            tmp.pop_back();
        }
    }
}
void work()
{
    
    cin>>a>>b;
    for(int i=1;i<=a;++i)cin>>x[i];
    sort(x+1,x+1+a);
    dfs(0);
    for(auto i:ans)cout<<i<<'\n';
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
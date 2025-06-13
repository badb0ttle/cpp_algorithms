/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=201;
int n,m,l,r,w;
struct node
{
    int u,v,w;
    bool operator<(const node &a) const
    {
        return w == a.w ? (u == a.u ? v < a.v : u < a.u) : w < a.w;
    }
};
int pre[mx];
int root(int v)
{
    return (pre[v] == v ? v : pre[v]=root(pre[v]));
}
vector<node>g;
void work()
{
    for(int i=1;i<=n;++i)pre[i]=i;
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=m;++i)
    {
        cin>>l>>r>>w;
        g.push_back({l,r,w});
    }
    sort(begin(g),end(g));
    for(auto&[u1,v1,w]:g)
    {
        if(root(u1)==root(v1))continue;
            pre[root(u1)]=root(v1);
            ans+=w;
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
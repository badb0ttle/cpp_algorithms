/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=1e6+1;
ll q,op,l,r,x,tCnt[mx<<2],tSum[mx<<2],n=mx;
void pushup(int v)
{
    tCnt[v]=tCnt[v<<1]+tCnt[v<<1|1];
    tSum[v]=tSum[v<<1]+tSum[v<<1|1];
}
void insert(ll v,ll s=1,ll e=n,ll o=1)
{
    if(s==e)return tCnt[o]++,tSum[o]+=v,void();
    ll mid=(s+e)>>1;
    if(v<=mid)insert(v,s,mid,o<<1);
    else insert(v,mid+1,e,o<<1|1);
    pushup(o);
}
ll queryCnt(ll l,ll r,ll s=1,ll e=n,ll o=1)
{
    if(l<=s&&r>=e)return tCnt[o];
    ll mid=(s+e)>>1;
    ll res=0;
    if(max(s,l)<=min(mid,e))res+=queryCnt(l,r,s,mid,o<<1);
    if(max(mid+1,l)<=min(r,e))res+=queryCnt(l,r,mid+1,e,o<<1|1);
    return res;
}
ll querySum(ll l,ll r,ll s=1,ll e=n,ll o=1)
{
    if(l<=s&&r>=e)return tSum[o];
    ll mid=(s+e)>>1;
    ll res=0;
    if(max(s,l)<=min(mid,e))res+=querySum(l,r,s,mid,o<<1);
    if(max(mid+1,l)<=min(r,e))res+=querySum(l,r,mid+1,e,o<<1|1);
    return res;
}
ll queryVal(ll k,ll s=1,ll e=n,ll o=1)
{
    if(s==e)return s;
    ll ls=tCnt[o<<1];
    ll mid=(s+e)>>1;
    if(k<=ls)return queryVal(k,s,mid,o<<1);
    return queryVal(k-ls,mid+1,e,o<<1|1);
}
ll m,tmp;
void work()
{
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>tmp;
        insert(tmp);
    }    
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<querySum(l,r)<<'\n';
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
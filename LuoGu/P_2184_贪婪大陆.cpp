/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 1e5 + 1;
int lz[mx << 2], t[mx << 2], a[mx], n, q;
void pushup(int x){ t[x]=t[x<<1]+t[x<<1|1];}    
void update(ll x,ll s=1,ll e=n,ll o=1)
{
    t[o]+=(e-s+1)*x;
    lz[o]+=x;
}
void pushdown(ll s=1,ll e=n,ll o=1)
{
    ll mid=(s+e)>>1;
    update(s,mid,o<<1);
    update(mid+1,e,o<<1|1);
    lz[o]=0;
}
void build(ll s=1,ll e=n,ll o=1)
{
    if(s==e)return t[o]=a[s],void();
    int mid=(s+e)>>1;
    build(s,mid,o<<1),build(mid+1,e,o<<1|1);
    pushup(o);
}
void add(ll l,ll r,ll s=1,ll e=n,ll o= 1)
{
    if(l<=s&&r>=e)return update(1,s,e,o),void();
    pushdown(s,e,o);
    int mid=(s+e)>>1;
    if(mid>=l)add(l,r,s,mid,o<<1);
    if(mid+1<=r)add(l,r,mid+1,e,o<<1|1);
    pushup(o);
}
int query(ll l,ll r,ll s=1,ll e=n,ll o= 1)
{
    if(l<=s&&r>=e)return t[o];
    pushdown(s,e,o);
    int mid=(s+e)>>1;
    int res=0;
    if(mid>=l)res+=query(l,r,s,mid,o<<1);
    if(mid+1<=r)res+=query(l,r,mid+1,e,o<<1|1);
    return res;
}
void work()
{
    cin >> n >> q;
    while (q--)
    {
        int op;
        cin>>op;
        int l,r;
        cin>>l>>r;
        if(op==1)
        {
            add(l,r);
        }
        else
        {
            cout<<query(l,r)<<'\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}
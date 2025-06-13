/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int  maxn=1e5+5;
struct Node
{
    int l,r;
    int val,key;
    int size;
    bool reverse;
}fhq[maxn];
int cnt,root;
mt19937 rnd(233);
int build(int val)
{
    fhq[++cnt].val=val;
    fhq[cnt].key=rnd();
    fhq[cnt].size=1;
    return cnt;
}
void pushup(int now)
{
    fhq[now].size=fhq[fhq[now].l].size+fhq[fhq[now].r].size+1;
}
void pushdown(int now)
{
    swap(fhq[now].l,fhq[now].r);
    fhq[fhq[now].l].reverse^=1;
    fhq[fhq[now].r].reverse^=1;
    fhq[now].reverse=false;
}
void split(int now,int siz,int &x,int &y)
{
    if(!now) x=y=0;
    else 
    {
        if(fhq[now].reverse) pushdown(now);
        if(fhq[fhq[now].l].size<siz)
        {
            x=now;
            split(fhq[now].r,siz-fhq[fhq[now].l].size-1,fhq[now].r,y);
        }
        else 
        {
            y=now;
            split(fhq[now].l,siz,x,fhq[now].l);
        }
        pushup(now);
    }
}
int merge(int x,int y)
{
    if(!x||!y) return x+y;
    if(fhq[x].key<fhq[y].key)
    {
        if(fhq[x].reverse) pushdown(x);
        fhq[x].r=merge(fhq[x].r,y);
        pushup(x);
        return x;
    }
    else 
    {
        if(fhq[y].reverse) pushdown(y);
        fhq[y].l=merge(x,fhq[y].l);
        pushup(y);
        return y;
    }
}
void reverse(int l,int r)
{
    int x,y,z;
    split(root,l-1,x,y);
    split(y,r-l+1,y,z);
    fhq[y].reverse^=1;
    root=merge(merge(x,y),z);
}
void ldr(int now)
{
    if(!now) return;
    if(fhq[now].reverse) pushdown(now);
    ldr(fhq[now].l);
    cout<<fhq[now].val<<' ';
    ldr(fhq[now].r);
}
void getvcnt(int v)//查询元素v的数量
{
    int T1, T2, T3;
    split(root, v - 1, T1, T2); // T1 < v, T2 >= v
    split(T2, v, T2, T3); // T2 == v, T3 > v
    int count = fhq[T2].size; // 计算 v 的数量
    root = merge(merge(T1, T2), T3); // 重新合并回去
    return count;
}
void work()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        root=merge(root,build(i));
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        reverse(l,r);
    }
    ldr(root);
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
/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx = 2e5 + 5;
mt19937 sj(1919810);
struct node
{
    int l, r;
    int key, v;
    int sz;
    int cnt[26];
    bool rev;
} fhq[mx];
int root, T1, T2, T3, idx, T4, T5;
int build(int v)
{
    fhq[++idx] = {0, 0, (int)sj(), v, 1};
    fhq[idx].cnt[v - 'a'] = 1;
    return idx;
}
void pushup(int v)
{
    fhq[v].sz = fhq[fhq[v].l].sz + fhq[fhq[v].r].sz + 1;
    for (int i = 0; i < 26; i++)
    {
        fhq[v].cnt[i] = fhq[fhq[v].l].cnt[i] + fhq[fhq[v].r].cnt[i];
    }
    fhq[v].cnt[fhq[v].v - 'a']++;
}
void pushdown(int u)
{
    swap(fhq[u].l,fhq[u].r);
    fhq[fhq[u].l].rev^=1;
    fhq[fhq[u].r].rev^=1;
    fhq[u].rev=0;
}
void split(int u, int k, int &x, int &y)
{
    if (!u)
    {
        x = y = 0;
        return;
    }
    if(fhq[u].rev) pushdown(u);
    if (fhq[fhq[u].l].sz >= k)
    {
        y = u;
        split(fhq[u].l, k, x, fhq[u].l);
    }
    else
    {
        x = u;
        split(fhq[u].r, k - fhq[fhq[u].l].sz - 1, fhq[u].r, y);
    }
    pushup(u);
}
int merge(int x, int y)
{
    if (!x || !y)
        return x + y;
    if (fhq[x].key < fhq[y].key)
    {
        fhq[x].r = merge(fhq[x].r, y);
        pushup(x);
        return x;
    }
    else
    {
        fhq[y].l = merge(x, fhq[y].l);
        pushup(y);
        return y;
    }
}
void ins(int v)
{
    split(root, v, T1, T2);
    root = merge(merge(T1, v), T2);
}
void del(int v)
{
    split(root, v, T1, T2);
    split(T1, v - 1, T1, T3);
    T3 = merge(fhq[T3].l, fhq[T3].r);
    root = merge(merge(T1, T3), T2);
}
int gr(int v)
{
    split(root, v - 1, T1, T2);
    int res = fhq[T1].sz + 1;
    merge(T1, T2);
    return res;
}
int kth(int k)
{
    int u = root;
    while (u)
    {
        int tmp = fhq[fhq[u].l].sz + 1;
        if (tmp == k)
            break;
        else if (tmp < k)
            u = fhq[u].l;
        else
        {
            k -= tmp;
            u = fhq[u].r;
        }
    }
    return fhq[u].v;
}
int gpre(int v)
{
    split(root, v - 1, T1, T2);
    int u = T1;
    while (fhq[u].r)
    {
        u = fhq[u].r;
    }
    root = merge(T1, T2);
    return fhq[u].v;
}
int gnext(int v)
{
    split(root, v, T1, T2);
    int u = T2;
    while (fhq[u].l)
    {
        u = fhq[u].l;
    }
    root = merge(T1, T2);
    return fhq[u].v;
}
void swp(int x1, int y1, int x2, int y2)
{
    split(root, x1 - 1, T1, T2);
    split(T2, y1 - x1 + 1, T2, T3);
    split(T3, x2 - y1 - 1, T3, T4);
    split(T4, y2 - x2 + 1, T4, T5);
    root = merge(merge(merge(merge(T1, T4), T3), T2), T5);
}

int gcnt(int x, int y, char c)
{
    split(root, y, T1, T3);
    split(T1, x - 1, T1, T2);
    int ans = fhq[T2].cnt[c - 'a'];
    root = merge(merge(T1, T2), T3);
    return ans;
}

void work()
{
    
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
/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 86401; 
struct node
{
    int l, r;
    int sum, id;
} t[4 * mx];

void pushup(int x)
{
    t[x].sum = max(t[x << 1].sum, t[x << 1 | 1].sum);
}

void pushdown(int x)
{
    if (t[x].id)
    {
        t[x << 1].sum += t[x].id;
        t[x << 1].id += t[x].id;
        t[x << 1 | 1].sum += t[x].id;
        t[x << 1 | 1].id += t[x].id;
        t[x].id = 0;
    }
}

void build(int x, int l, int r)
{
    t[x] = {l, r, 0, 0};
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
}

void modify(int x, int l, int r, int d)
{
    if (t[x].l >= l && t[x].r <= r)
    {
        t[x].sum += d;
        t[x].id += d;
        return;
    }
    pushdown(x);
    int mid = (t[x].l + t[x].r) >> 1;
    if (l <= mid)
        modify(x << 1, l, r, d);
    if (r > mid)
        modify(x << 1 | 1, l, r, d);
    pushup(x);
}

int gtim(string t)
{
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    int s = stoi(t.substr(6, 2));
    return h * 3600 + m * 60 + s + 1;
}
int n;
string t1, t2;
void work()
{
    cin >> n;
    build(1, 1, 86400);
    for (int i = 1; i <= n; ++i)
    {
        cin >> t1 >> t2;
        int l = gtim(t1), r = gtim(t2);
        modify(1, l, r, 1);
    }
    cout << t[1].sum << '\n';
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
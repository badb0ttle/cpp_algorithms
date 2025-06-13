/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 1e5 + 10;
double n, id[mx], k, tid;
double z, r, sum;
struct node
{
    double v;
    vector<int> child;
    int f = 0;
};
vector<node> g(mx);
void bfs()
{
    queue<double> q;
    q.push(0); 
    while (!q.empty())
    {
        double x = q.front();
        q.pop();
        for (double i : g[x].child)
        {
            if (g[i].f) 
            {
                sum += g[x].v *(1-z)* g[i].f;
            }
            else
            {
                g[i].v = g[x].v * (1 - z);
               q.push(i);
            } 
        }
    }
}
void work()
{
    double bs;
    cin >> n >> r >> z;
    z = 1.0 * z / 100;
    for (double i = 0; i < n; ++i)
    {
        cin >> k;
        if (!k)
            {cin>>bs;g[i].f = bs;}
        for (int j = 1; j <= k; ++j)
        {
            double tid;
            cin >> tid;
            g[i].child.push_back(tid);
        }
    }
    g[0].v = r;
    bfs();
    cout << (int)sum << '\n';
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
/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define ull unsigned long long
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 2e6 + 1;
int m;
int circnt;
int x,y;
vector<int>g[mx];
bool vis[mx];
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    vis[x] = 1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto i : g[t])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}
void work()
{
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=m;++i)
    {
        if(!vis[i])
        {
            circnt++;
            bfs(i);
        }
    }
    cout<<circnt<<'\n';
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
